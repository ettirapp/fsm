// Initialize fsm matrix to -1's so we will be able to see if an element
// has been set yet.
void initializeMatrix(int fsm[50][52])
{
for (int i = 0; i < 50; i++)
    {
      for (int j = 0; j < 52; j++)
	{
          fsm[i][j] = -1;
	}
    }
}
