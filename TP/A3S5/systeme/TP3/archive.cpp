unsigned int r = createMask(0, 7);
	unsigned int result=0;
	for(int i=0; i<8; i++)
	{
		// bitset<16>A = fra.page[i];
		result = r & fra.page[i];
	}
	// for(int i=0; i<8; i++)
	// {
	// 	// bitset<16>A = fra.page[i];
	// 	result = r & fra.offset[i];
	// }