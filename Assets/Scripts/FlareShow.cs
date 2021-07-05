using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FlareShow : MonoBehaviour
{
    public GameObject prefab;
	public float minDelay, maxDelay;
	public float minSpeed, maxSpeed;
	public float minOff, maxOff;
	public float minY, maxY;
	public float sat;

	private void Start() =>
		StartCoroutine(SpawnLoop());

	private IEnumerator SpawnLoop()
	{
	Loop:
		var obj = Instantiate(prefab);
		var firework = obj.GetComponent<Firework>();
		firework.speed = Random.Range(minSpeed, maxSpeed);
		firework.off = Random.Range(minOff, maxOff);
		firework.end = Random.Range(minY, maxY);
		var settings = firework.flare.main;
		settings.startColor = Color.HSVToRGB(Random.value, sat, 1);

		yield return new WaitForSeconds(Random.Range(minDelay, maxDelay));
		goto Loop;
	}
}
