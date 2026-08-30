def find_indices(dictionaire, hindice):
	return {k:v for k, v in dictionaire.items() if hindice in v}

d = {'A': [1, 2, 3, 4], 'B': [6, 2, 4, 6, 8], 'C': [3, 6, 9, 12]}
print(find_indices(d, 6))