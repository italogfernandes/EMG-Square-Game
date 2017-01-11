using UnityEngine;
using System.Collections;

public class BlocoBehavior : MonoBehaviour {

	public float speed;
	public GameObject bloco;
	//private PlayerControl player;
	//private bool passou;
    private SpawObject spawn;
    


	void Start () {

        //player = FindObjectOfType (typeof(PlayerControl)) as PlayerControl;
        spawn = FindObjectOfType(typeof(SpawObject)) as SpawObject;
       


    }
	//void OnLable(){

	//		passou = false;
	//}

  

	// Update is called once per frame
	void Update () {


        if (Time.timeSinceLevelLoad >= 70)
        {
            speed = -35;
            spawn.rate = 0.1f;
        }
        else
        {
            if (Time.timeSinceLevelLoad >= 50)
            {
                speed = -25;
                spawn.rate = 0.2f;
            }
            else
            {
                if (Time.timeSinceLevelLoad >= 30)
                {
                    speed = -20;
                    spawn.rate = 0.4f;
                }
                else
                {
                    if (Time.timeSinceLevelLoad >= 20)
                    {
                        speed = -15;
                        spawn.rate = 0.5f;
                    }
                    else
                    {
                        if (Time.timeSinceLevelLoad >= 12)
                        {
                            speed = -11;
                            spawn.rate = 0.7f;
                        }
                        else
                        {
                            if (Time.timeSinceLevelLoad >= 8)
                                speed = -8;
                  
                        }
                    }
                }
            }
        }

        transform.position += new Vector3 (speed, 0, 0) * Time.deltaTime;

        //if (transform.position.x < player.transform.position.x && !passou)
        //{

        //    player.addscoore();
        //    passou = true;
        //    Debug.Log(player.scoore);


        //}

		if (transform.position.x < -10) {
			bloco.SetActive (false);
		}
		}
}
