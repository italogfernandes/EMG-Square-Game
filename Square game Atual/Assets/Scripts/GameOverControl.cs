using UnityEngine;
using System.Collections;

public class GameOverControl : MonoBehaviour {

	public TextMesh pontos;



	// Use this for initialization
	void Start () {
	
	}


	
	// Update is called once per frame
	void Update () {


		if(Input.GetButtonDown("Fire1")){
			Application.LoadLevel("Start");
		}
	}
}
