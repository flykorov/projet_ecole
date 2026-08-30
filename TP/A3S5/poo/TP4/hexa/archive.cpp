
void Hexa::int_to_char(int con)					// affecte le bon chiffre/lettre correspondant 
{
	switch(con)
	{
		case 0 : hexadecimal.push_back('0');
			break;
		case 1 : hexadecimal.push_back('1');
			break;
		case 2 : hexadecimal.push_back('2');
			break; 
		case 3 : hexadecimal.push_back('3');
			break;
		case 4 : hexadecimal.push_back('4');
			break; 
		case 5 : hexadecimal.push_back('5');
			break; 
		case 6 : hexadecimal.push_back('6');
			break; 
		case 7 : hexadecimal.push_back('7');
			break; 
		case 8 : hexadecimal.push_back('8');
			break; 
		case 9 : hexadecimal.push_back('9');
			break; 
		case 10 : hexadecimal.push_back('a');
			break; 
		case 11 : hexadecimal.push_back('b');
			break; 
		case 12 : hexadecimal.push_back('c');
			break; 
		case 13 : hexadecimal.push_back('d');
			break; 
		case 14 : hexadecimal.push_back('e');
			break; 
		case 15 : hexadecimal.push_back('f');
			break;
	}
}

vector<char> Hexa::convert_hexa(int nombre)
{
	hexadecimal.clear();
	setNombre(nombre);
	dec_to_bin();
	bin_to_hexa();
	return getHexadecimal();
}