using UnityEngine;
using System.Collections;

public class PlayerControl : MonoBehaviour {

	public GameObject player;
	public float maxima;
	public float minima;
	float atual;
	//public int scoore;

	public TextMesh pontos;


	// Use this for initialization
	void Start () {
		atual = minima;
	}
	
	// Update is called once per frame
	void Update () {
		if (atual == minima) {
	
			if (Input.GetKeyUp ("space")){
				player.transform.Translate (0, maxima, 0);
				atual = maxima;
	
			}
		} else {
			if (Input.GetKeyUp("space")) {
				player.transform.Translate (0, minima, 0);
				atual = minima;
			
			}
		}

		//pontos.text = scoore.ToString();
	}

	void OnTriggerEnter2D(Collider2D col){

		Application.LoadLevel ("GameOver");
	}

	//public void addscoore(){
	//	scoore++;
	//}


}

