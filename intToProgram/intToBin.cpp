void intToBin(int input)
{
	int binary_array[100], i = 0, j;

	while (input > 0)
	{
		binary_array[i] = input % 2;
		i++;
		input = input / 2;
	}

	cout << "Binary: ";

	for (j = i - 1; j >= 0; j--)
	{
		cout << binary_array[j];
	}

	cout << "b";
}
