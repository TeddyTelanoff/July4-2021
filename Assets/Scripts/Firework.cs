using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Firework : MonoBehaviour
{
	public GameObject model;
    public ParticleSystem flare, trail;
	public float speed, end, off, dir;
	public float vel;

	private void Start() =>
		transform.rotation = Quaternion.Euler(off, dir = Random.Range(0.0f, 360), 0);

	private void FixedUpdate()
	{
		if (transform.position.y > end)
			StartCoroutine(Flare());
		else
		{
			vel += speed * Time.deltaTime;
			transform.position += vel * transform.up;

			off += off * .5f * Time.deltaTime;
			transform.rotation = Quaternion.Euler(off, dir, 0);
		}
	}

	private IEnumerator Flare()
	{
		flare.Play();
		trail.Stop();
		Destroy(model);
		yield return new WaitForSeconds(flare.main.duration);
		yield return new WaitForEndOfFrame();
		Destroy(gameObject);
	}
}
