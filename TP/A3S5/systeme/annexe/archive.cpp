// int a=0, b;
	// do
	// {

	// 	sem_getvalue(&au, &b);
	// 	a++;
	// 	switch(b)
	// 	{
	// 		case 1: 
	// 		sem_wait(&au);
	// 		cout << "coupe de vin possede or\n";
	// 		cout << "coupe de vin en creation\n";
	// 		// this_thread::sleep_for(chrono::milliseconds(200));
	// 		result[0]++;
	// 		sem_post(&ar);
	// 		sem_post(&au);
	// 		sem_post(&la_th);
	// 		sem_post(&nb_th);
	// 		sem_post(&t1);
	// 		break;
	// 		case 0: 
			
	// 		if(a >= 10)
	// 		{
	// 			cout << "coupe de vin attend or\n";
	// 			sem_post(&ar);
	// 			sem_post(&la_th);
	// 			sem_post(&nb_th);
	// 			sem_post(&t1);
	// 		}
	// 		break;
	// 	}
	// }while(b==0 && a<10);

int a=0, b;
	do
	{	
		sem_getvalue(&ar, &b);
		a++;
		switch(b)
		{
			case 1: 
			sem_wait(&bo);
			cout << "porte possede bois\n";
			cout << "porte en creation\n";
			// this_thread::sleep_for(chrono::milliseconds(200));
			result[1]++;
			sem_post(&au);
			sem_post(&bo);
			sem_post(&la_th);
			sem_post(&nb_th);
			sem_post(&t2);
			break;
			case 0: 
			
			if(a >= 10)
			{
				cout << "porte attend bois\n";
				sem_post(&au);
				sem_post(&la_th);
				sem_post(&nb_th);
				sem_post(&t2);
			}
			break;
		}
	}while(b==0 && a<10);
	cout << "porte " << result[1] << endl;

	int a=0, b;
	do
	{
		
		sem_getvalue(&ar, &b);
		a++;
		switch(b)
		{
			case 1: 
			sem_wait(&me);
			cout << "table possede metal\n";
			cout << "table en creation\n";
			// this_thread::sleep_for(chrono::milliseconds(200));
			result[2]++;
			sem_post(&bo);
			sem_post(&me);
			sem_post(&la_th);
			sem_post(&nb_th);
			sem_post(&t3);
			break;
			case 0: 
			
			if(a >= 10)
			{
				cout << "table attend metal\n";
				sem_post(&bo);
				sem_post(&la_th);
				sem_post(&nb_th);
				sem_post(&t3);
			}
			break;
		}
	}while(b==0 && a<10);
	cout << "table " << result[2] << endl;

	int a=0, b;
	do
	{
		
		sem_getvalue(&ar, &b);
		a++;
		switch(b)
		{
			case 1: 
			sem_wait(&di);
			cout << "bague possede diamant\n";
			cout << "bague en creation\n";
			// this_thread::sleep_for(chrono::milliseconds(200));
			result[3]++;
			sem_post(&di);
			sem_post(&me);
			sem_post(&la_th);
			sem_post(&nb_th);
			sem_post(&t5);
			break;
			case 0: 
			
			if(a >= 10)
			{
				cout << "bague attend diamant\n";
				sem_post(&me);
				sem_post(&la_th);
				sem_post(&nb_th);
				sem_post(&t5);
			}
			break;
		}
	}while(b==0 && a<10);
	cout << "bague "<< result[3] << endl;

	int a=0, b;
	do
	{
		
		sem_getvalue(&ar, &b);
		a++;
		switch(b)
		{
			case 1: 
			sem_wait(&fe);
			cout << "chandelier possede fer\n";
			cout << "chandelier en creation\n";
			// this_thread::sleep_for(chrono::milliseconds(200));
			result[4]++;
			sem_post(&fe);
			sem_post(&di);
			sem_post(&la_th);
			sem_post(&nb_th);
			sem_post(&t6);
			break;
			case 0: 
			
			if(a >= 10)
			{
				cout << "chandelier attend fer\n";
				sem_post(&di);
				sem_post(&la_th);
				sem_post(&nb_th);
				sem_post(&t6);
			}
			break;
		}
	}while(b==0 && a<10);
	cout << "chandelier " << result[4] << endl;

	int a=0, b;
	do
	{
		
		sem_getvalue(&ar, &b);
		a++;
		switch(b)
		{
			case 1: 
			sem_wait(&ar);
			cout << "epee possede argent\n";
			cout << "epee en creation\n";
			// this_thread::sleep_for(chrono::milliseconds(200));
			result[5]++;
			sem_post(&fe);
			sem_post(&ar);
			sem_post(&la_th);
			sem_post(&nb_th);
			sem_post(&t4);
			break;
			case 0: 
			if(a >= 10)
			{
				cout << "epee attend argent\n";
				sem_post(&fe);
				sem_post(&la_th);
				sem_post(&nb_th);
				sem_post(&t4);
			}
			break;
		}
	}while(b==0 && a<10);
	cout << "epee "<< result[5] << endl;

	// int b;
	// sem_getvalue(&fe, &b);
	// switch(b)
	// {
	// 	case 1: cout << "";
	// 		break;
	// 	case 0: cout << "chandelier attend fer\n";
	// 		break;
	// }

	// do
	// {
	// 	sem_getvalue(&ar, &u);			// verifie la disponibilite de la ressource
	// 	if(u==0)
	// 	{
	// 		// cout << "coupe de vin attend argent\n";
	// 		// sem_wait(&att_t1);			// met en pose le thread si la ressource n'est pas disponible
	// 		// sem_post(&att_t1);
			
	// 	}
	// 	sem_getvalue(&au, &v);			// meme chose
	// 	if(v==0)
	// 	{
	// 		// cout << "coupe de vin attend or\n";
	// 		// sem_wait(&att_t1);
	// 		// sem_post(&att_t1);
	// 	}
	// }while(u==0 || v==0);


	// sem_getvalue(&nb_th, &q);
		// if(q>0)
		// {
		// 	if(prio.empty() == 1)
		// 	{
		// 		thread coupe(coupe_de_vin, result, ressource);
		// 		thread tabl(table, result, ressource);
		// 		thread bag(bague, result, ressource);
		// 		thread epe(epee, result, ressource);
		// 		thread chand(chandelier, result, ressource);
		// 		thread port(porte, result, ressource);
		// 		if(coupe.joinable())
		// 			coupe.detach();
		// 		if(tabl.joinable())
		// 			tabl.detach();
		// 		if(bag.joinable())
		// 			bag.detach();
		// 		if(epe.joinable())
		// 			epe.detach();
		// 		if(chand.joinable())
		// 			chand.detach();
		// 		if(port.joinable())
		// 			port.detach();
		// 	}else
		// 	{
		// 		for(i=0; i<q; i++)
		// 		{
		// 			if(prio.empty() == 0)
		// 			{
		// 				int a, b;
		// 				if(prio.front() == 1)
		// 				{
		// 					sem_wait(&res);
		// 					a = result[0];
		// 					sem_post(&res);
		// 					thread coupe(coupe_de_vin, result, ressource);
		// 					if(coupe.joinable())
		// 						coupe.detach();
		// 					sem_wait(&res);
		// 					b = result[0];
		// 					sem_post(&res);
		// 					prio.pop_front();
		// 				}
		// 				if(prio.front() == 2)
		// 				{
		// 					sem_wait(&res);
		// 					a = result[1];
		// 					sem_post(&res);
		// 					thread port(porte, result, ressource);
		// 					if(port.joinable())
		// 						port.detach();
		// 					sem_wait(&res);
		// 					b = result[1];
		// 					sem_post(&res);
		// 					prio.pop_front();
		// 				}
		// 				if(prio.front() == 3)
		// 				{
		// 					sem_wait(&res);
		// 					a = result[2];
		// 					sem_post(&res);
		// 					thread tabl(table, result, ressource);
		// 					if(tabl.joinable())
		// 						tabl.detach();
		// 					sem_wait(&res);
		// 					b = result[2];
		// 					sem_post(&res);
		// 					prio.pop_front();
		// 				}
		// 				if(prio.front() == 4)
		// 				{
		// 					sem_wait(&res);
		// 					a = result[3];
		// 					sem_post(&res);
		// 					thread bag(bague, result, ressource);
		// 					if(bag.joinable())
		// 						bag.detach();
		// 					sem_wait(&res);
		// 					b = result[3];
		// 					sem_post(&res);
		// 					prio.pop_front();
		// 				}						
		// 				if(prio.front() == 5)
		// 				{
		// 					sem_wait(&res);
		// 					a = result[4];
		// 					sem_post(&res);
		// 					thread chand(chandelier, result, ressource);
		// 					if(chand.joinable())
		// 						chand.detach();
		// 					sem_wait(&res);
		// 					b = result[4];
		// 					sem_post(&res);
		// 					prio.pop_front();
		// 				}
						
		// 				if(prio.front() == 6)
		// 				{
		// 					sem_wait(&res);
		// 					a = result[5];
		// 					sem_post(&res);
		// 					thread epe(epee, result, ressource);
		// 					if(epe.joinable())
		// 						epe.detach();
		// 					sem_wait(&res);
		// 					b = result[5];
		// 					sem_post(&res);
		// 					prio.pop_front();
		// 				}						
		// 			}
		// 		}
		// 	}