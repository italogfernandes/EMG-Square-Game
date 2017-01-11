using UnityEngine;
public class ObstacleGameOver : MonoBehaviour

{
    
    public Vector2 jumpForce = new Vector2(0, 300);
 
    // Use this for initialization
    void Start()
    {
        GetComponent<Rigidbody2D>().velocity = Vector2.zero;
        GetComponent<Rigidbody2D>().AddForce(jumpForce);
      
    }

}