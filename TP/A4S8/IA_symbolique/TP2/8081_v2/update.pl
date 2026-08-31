:- module(update, [calculer_action_croyances/4]).

:- use_module(library(http/http_json)).
:- use_module(library(clpfd)).

% Pour debuger
:- use_module(library(http/http_log)).

:- use_module(direction).
:- use_module(has_gold).
:- use_module(action).
:- use_module(visited).
:- use_module(pit).
:- use_module(wumpus).
:- use_module(exit).
:- use_module(adjacent).
:- use_module(decompose).

calculer_action_croyances(HunterBeliefs, Percepts, FinalBeliefs, Action) :-

	% Mise a jour des nouvelles croyances : 
	adjacent(HunterBeliefs.certain_eternals.cells, HunterBeliefs.certain_fluents.fat_hunter.c, CasesAdjacentes),
	updateEatPit(Percepts, HunterBeliefs.certain_fluents.fat_hunter.c, CasesAdjacentes, HunterBeliefs.certain_eternals.eat_walls, HunterBeliefs.uncertain_eternals, New_Uncertain_Eternals),
	updateEatWumpus(Percepts, HunterBeliefs.certain_fluents.fat_hunter.c, CasesAdjacentes, HunterBeliefs.certain_eternals.eat_walls, New_Uncertain_Eternals, Final_Uncertain_Eternals),
	NewBeliefs = HunterBeliefs.put(uncertain_eternals, Final_Uncertain_Eternals),
	
	% Détermination de l'action à jouer :
	(HunterBeliefs.certain_fluents.has_gold = [] -> 
		action(Percepts, CasesAdjacentes, NewBeliefs, Action),
		updateVisited(Action, HunterBeliefs.certain_fluents, New_Certain_Fluents_V1);
		remonter_chemin(HunterBeliefs.certain_fluents.visited, Case),
		action_postGold(HunterBeliefs.certain_fluents.fat_hunter, Case, HunterBeliefs.certain_fluents.dir, HunterBeliefs.certain_eternals.eat_exit.c, Action),
		enleverCase(Action, HunterBeliefs.certain_fluents.visited, HunterBeliefs.certain_fluents, New_Certain_Fluents_V1)
	),

	% Mise a jour du jeu pour la prochaine itération :
	updateDir(Action, New_Certain_Fluents_V1, New_Certain_Fluents_V2),
	updateHasGold(Action, Percepts ,New_Certain_Fluents_V2, New_Certain_Fluents_V3),
	
	FinalBeliefs = HunterBeliefs.put(certain_fluents, New_Certain_Fluents_V3).put(uncertain_eternals, Final_Uncertain_Eternals).
