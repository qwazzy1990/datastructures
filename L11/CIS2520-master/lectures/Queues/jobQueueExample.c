int countTime(Queue* q)
{
	int count = 0;
	int maxTime = 4;
	while(!isEmpty(q))
	{
		// Get the front of the queue
		int* n = (int*)dequeue(q);
			
		// If the N was more than max time sub track the time
		if( *n > maxTime)
		{
			// remove the 4 seconds and add 2 seconds for back of the line
			*n = (*n - maxTime +2);
			enqueue(q,n);
			count += 4;
		}
		else
		{
			count += *n;
		}
	}
}