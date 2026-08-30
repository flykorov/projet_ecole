for(it=gestion.begin(); it!=gestion.end(); it++)
	{
		// const type_info& t = typeid(gestion[0]);
		// cout << t.name() << endl;
		Concepteur* temp = dynamic_cast<Concepteur*>(*it);
		const type_info& t = typeid(temp);
		cout << t.name() << endl;
		// if(typeid(*it) == dynamic_cast<Concepteur*>(*it))
		// 	cout << "oohhh\n";
		if(temp != nullptr)
		{
			delete temp;
			gestion.erase(it);
			cout << "bi\n";
			if(gestion.empty() == 1)
				return;
			else
				it = gestion.begin();
			
		}else
		{
			cout << "bru\n";
		}
	}


unsigned long int i;
for(i=0; i<gestion.size(); i++)
{
	Concepteur* temp = dynamic_cast<Concepteur*>(*it);
	if(temp != nullptr)
	{
		delete temp;
		gestion.erase(i);
		cout << "bi\n";
		if(gestion.empty() == 1)
			return;
		else
			i=0;
		
	}else
	{
		cout << "bru\n";
	}
}