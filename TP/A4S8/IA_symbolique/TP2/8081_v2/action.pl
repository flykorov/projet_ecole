:- module(action, [action/4, action_postGold/5]).

% Pour debuger
:- use_module(library(http/http_log)).

:- use_module(library(clpfd)).
:- use_module(pos).
:- use_module(library(lists)).


setXY(north, X, Y, Fat_hunter) :- 
	X #= Fat_hunter.c.x,
	Y #= Fat_hunter.c.y + 1.

setXY(south, X, Y, Fat_hunter) :- 
	X #= Fat_hunter.c.x,
	Y #= Fat_hunter.c.y - 1.

setXY(east, X, Y, Fat_hunter) :- 
	X #= Fat_hunter.c.x + 1,
	Y #= Fat_hunter.c.y.

setXY(west, X, Y, Fat_hunter) :- 
	X #= Fat_hunter.c.x - 1,
	Y #= Fat_hunter.c.y.


% On détermine ici les action à réaliser si on prend pas le gold :
actionNoGrab(Percepts, CasesAdjacentes, HunterBeliefs, Action) :-
	% On détermine les cases autorisées :
    trouver_case(CasesAdjacentes, HunterBeliefs.certain_eternals.eat_walls, AdjSansWalls), % On enléve les walls
	trouver_case_pit(AdjSansWalls, HunterBeliefs.uncertain_eternals.eat_pit, AdjSansPits), % enleve pits
	%http_log('La valeur de AdjSansPits est : ~w\n', [AdjSansPits]),
	trouver_case_wumpus(AdjSansPits, HunterBeliefs.uncertain_eternals.eat_wumpus, AdjSansWumpus), % enleve wumpus
	http_log('La valeur de AdjSansWumpus est : ~w\n', [AdjSansWumpus]),

	% AdjSansWumpus -> liste qui contien les cases adjacentes autorisées 
	%HunterBeliefs.certain_fluents.dir{d:Dir, h:hunter{id:hunter}}, % Récup direction
	HunterBeliefs.certain_fluents.dir = [dir{d:Dir, h:hunter{id:hunter}}],

	interface_visited_pos(HunterBeliefs.certain_fluents.visited, Visite), % Recup les cases deja visites
	trouver_case_visite(AdjSansWumpus, Visite, CasesAutorise), % On retire les cases visités SAUF si pas le choix
	http_log('Cases Auth est : ~w\n', [CasesAutorise]),

	setXY(Dir, X, Y, HunterBeliefs.certain_fluents.fat_hunter),
	http_log('La valeur de X est : ~w\n', [X]),
	http_log('La valeur de Y est : ~w\n', [Y]),

	(member(_{x:X,y:Y}, CasesAutorise) -> 
		Action = forward;
		Action = left
	).
	%Action = forward.

    


% Si glitter, on prend le gold et rien d'autre:
action(Percepts, CasesAdjacentes, HunterBeliefs, Action) :-
    (member(glitter, Percepts) ->
		Action = grab;
		actionNoGrab(Percepts, CasesAdjacentes, HunterBeliefs, Action)
	).

% Apres le gold :
dir_postGold(Hunter, Case, Dir, Action) :-
	setXY(Dir, X, Y, Hunter),
	(_{x:X, y:Y} = Case ->
		Action = forward;
		Action = right
	).


action_postGold(Hunter, Case, Direction, Exit, Action) :-
	Direction = [dir{d:Dir, h:hunter{id:hunter}}],
	(Exit = Hunter.c ->
		Action = climb;
		dir_postGold(Hunter, Case, Dir, Action)
	).