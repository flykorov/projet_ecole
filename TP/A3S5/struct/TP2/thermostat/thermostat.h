#ifndef THERMOSTAT_H
#define THERMOSTAT_H

class Thermostat
{
public:
	Thermostat();
	Thermostat(bool m) : mode(m) {}
	~Thermostat();

	void afficher_option();
	char get_mode();
	int get_zone();
	int* get_temperature();
	int get_temperature_manuel();

	friend std::ostream& operator<<(std::ostream& os, Thermostat const & t);	// affichage en surcharge pour le Template


	bool choix(Thermostat thermometre);
	void afficher_thermostat();		// meme affichage que le ostream
	void ajuster_temperature();
	void definir_mode();

private:
	char mode = 'A';
	int zone = 1;
	int temperature[3] = {10, 10, 10};
	int temperature_manuel = 10;

	void set_mode(char _mode);
	void set_zone(int _zone);
	void set_temperature(int* _temperature);
	void set_temperature_manuel(int _temperature_manuel);
};

#endif