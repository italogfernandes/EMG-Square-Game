int tensao = 0;//sera convertida p/ milivolts

const int musculo = 13;
const int alerta1 = 11;
const int alerta2 = 12;
const int saida[7] = {3,4,5,6,7,8,9};

int Minimo = 0;
int Maximo = 0;
int amp = 0;//amplitude
int cont_loop2 = 0;

int flexionado = 0;

int minpadrao = 0;
int maxpadrao = 0;
int amppadrao = 0;

int minforte = 0;
int maxforte = 0;
int ampforte = 0;

int dif = 0; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
	for(int i=0; i<7; i++)
	{
		pinMode(saida[i], OUTPUT); 
	}
  pinMode(alerta1, OUTPUT);  
	pinMode(alerta2, OUTPUT); 
  pinMode(musculo, OUTPUT); 

	calibrar();
}

void loop() {

  tensao = (analogRead(A0)*5-2560)*1000/512;
  if(tensao > 4900)//Indicador de tensao mto alta
  {
     digitalWrite(alerta1, HIGH);    
  } else
  {
    digitalWrite(alerta1, LOW);
  } 
  if(tensao < -4900)//Indicador de tensao mto baixa
  {
     digitalWrite(alerta2, HIGH);    
  } else
  {
    digitalWrite(alerta2, LOW);
  } 
	//////////////////
  if(tensao > Maximo)//procura o maximo
  {
     Maximo = tensao;   
  }
  
  if(tensao < Minimo)//procura o minimo
  {
     Minimo = tensao;   
  }

  delay(1);//lendo a cada 1 milisegundo
////////////////////////////////////////////////////////////////
  cont_loop2 ++;//contando ate 50 milisegundos
  if (cont_loop2 >= 50)//loop de a cada 50 milisegundos
  {
		amp = Maximo - Minimo;
		for(int i=0; i<7; i++)//exibindo na barra de leds
		{
			if(Maximo > i*100)
			{
				digitalWrite(saida[i], HIGH);
			} else
			{
				digitalWrite(saida[i], LOW);
			}
		}    

    if(amppadrao < amp && amp < ampforte+(dif/2))//verificando o sinal
    {
       digitalWrite(musculo, HIGH);
       flexionado = 1;
    } else
    {
      digitalWrite(musculo, LOW);
      flexionado = 0;
    }
		Serial.print("Min= "); // exibição para debug
  	Serial.print(Minimo);
		Serial.print("    Max= ");
		Serial.println(Maximo);

    Minimo = 0;//reiniciar loop
    Maximo = 0; 
		cont_loop2 = 0;
  }
}

/////////////////////////////////////////////////////////////////////////////
void calibrar() {
	digitalWrite(alerta1, HIGH); 
	digitalWrite(alerta2, HIGH);
	//aviso
	for(int i=0; i<7; i++)//7 piscadas de aviso
	{
		digitalWrite(saida[i], HIGH); 
		delay(500);
		digitalWrite(saida[i], LOW);
		delay(500); 
	}

	//calibragem
	for(int i=0; i<500; i++)//Calibra com a pessoa parada
	{
		tensao = (analogRead(A0)*5-2560)*1000/512;
		if(tensao > Maximo)
 		{
			Maximo = tensao;
		}
		if(tensao < Minimo)
 		{
			Minimo = tensao;
		}
		delay(1);
		cont_loop2 ++;
		if (cont_loop2 >= 50)//capturando dados a cada 50ms
		{
			amppadrao += Maximo - Minimo;
			minpadrao += Minimo;
  	  maxpadrao += Maximo;

		  Minimo = 0;//reiniciar loop
		  Maximo = 0; 
			cont_loop2 = 0;
		}	
	}
	amppadrao /= 10;
	minpadrao /= 10;
	maxpadrao /= 10;
	
	//aviso
	for(int i=0; i<7; i--)//7 piscadas de aviso
	{
		digitalWrite(saida[i], HIGH); 
		delay(500);
		digitalWrite(saida[i], LOW);
		delay(500); 
	}

	//calibragem em movimento
	for(int i=0; i<500; i++)//Calibra com a pessoa forçando
	{
		tensao = (analogRead(A0)*5-2560)*1000/512;
		if(tensao > Maximo)
 		{
			Maximo = tensao;
		}
		if(tensao < Minimo)
 		{
			Minimo = tensao;
		}
		delay(1);
		cont_loop2 ++;
		if (cont_loop2 >= 50)//capturando dados a cada 50ms
		{
			ampforte += Maximo - Minimo;
			minforte += Minimo;
  	  maxforte += Maximo;

		  Minimo = 0;//reiniciar loop
		  Maximo = 0; 
			cont_loop2 = 0;
		}	
	}
	ampforte /= 10;
	minforte /= 10;
	maxforte /= 10;
	
	dif = ampforte - amppadrao;

	for(int i=0; i<3; i++)//aviso de calibrado
	{
		for(int j=0; j<7; j++)
		{
			digitalWrite(saida[i], HIGH); 
		}
		delay(500);

		for(int j=0; j<7; j++)
		{
			digitalWrite(saida[i], LOW); 
		}
		delay(500); 
	}
}
