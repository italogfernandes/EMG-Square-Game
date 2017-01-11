using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class SpawObject : MonoBehaviour {

	public float max;
	public float min;
	public float rate;
	private float current;
	public int maxbloco;
	public GameObject prefab;
	public List<GameObject> bloco;
	private float randPosition; 


	// Use this for initialization
	void Start () {
	
		for (int i = 0; i < maxbloco; i++) {
			GameObject tempbloco = Instantiate(prefab)as GameObject;
			bloco.Add (tempbloco);
			tempbloco.SetActive(false);
		}
	}
	
	// Update is called once per frame
	void Update () {

		current += Time.deltaTime;
		if (current > rate){
			current = 0;
			Spawn();
		}

	
	}

	private void Spawn(){
		int rand = Random.Range (0, 10);
		if (rand % 2 == 0) {
			randPosition = min;
		} 
		else {
			randPosition = max;
		}

		GameObject tempbloco = null;
		for (int i = 0; i < maxbloco; i++) {
			if (bloco [i].activeSelf == false) {
				tempbloco = bloco [i];
				break;
			}

		}
		if (tempbloco != null) {
			tempbloco.transform.position = new Vector3 (transform.position.x, randPosition, transform.position.z);
			tempbloco.SetActive (true);
		}

	}

}
