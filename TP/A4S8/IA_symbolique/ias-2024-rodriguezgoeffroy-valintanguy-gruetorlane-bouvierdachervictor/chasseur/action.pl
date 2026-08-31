:- module(action, [action/4, action_postGold/5]).

:- use_module(library(http/http_log)).
:- use_module(library(clpfd)).
:- use_module(pos).
:- use_module(library(lists)).

% Prédicats pour détécter la case vers laquel le hunter se dirige en fonction de sa position et de son orientation :
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
	trouver_case_pit(AdjSansWalls, HunterBeliefs.uncertain_eternals.eat_pit, AdjSansPits), % On enleve les pits
	trouver_case_wumpus(AdjSansPits, HunterBeliefs.uncertain_eternals.eat_wumpus, AdjSansWumpus), % On enleve les wumpus

	% AdjSansWumpus est une liste des cases adjacentes au hunter sur lesquels on est certain qu'il n'y a ni pits, ni wumpus
	
	% Récupération de la direction du Hunter 
	HunterBeliefs.certain_fluents.dir = [dir{d:Dir, h:hunter{id:hunter}}],

	% Recupération des cases deja visitées :
	interface_visited_pos(HunterBeliefs.certain_fluents.visited, Visite),

	% On retire les cases visités de la liste des cases authorisées SAUF si on à pas le choix (Sauf si on est encerclés de pits et wumpus, dans ce cas on peut revenir en arriére):
	trouver_case_visite(AdjSansWumpus, Visite, CasesAutorise),

	% On récupére la cases vers laquel le hunter se dirige 
	setXY(Dir, X, Y, HunterBeliefs.certain_fluents.fat_hunter),

	% Si la case fait partie des cases 'authorisées', on va dessus, sinon, on tourne a gauche
	(member(_{x:X,y:Y}, CasesAutorise) -> 
		Action = forward;
		Action = left
	).

% Si glitter, on prend le gold et rien d'autre:
action(Percepts, CasesAdjacentes, HunterBeliefs, Action) :-
    (member(glitter, Percepts) ->
		Action = grab;
		actionNoGrab(Percepts, CasesAdjacentes, HunterBeliefs, Action)
	).

% choisi l'action du chasseur si il n'est pas sur la sortie
dir_postGold(Hunter, Case, Dir, Action) :-
	setXY(Dir, X, Y, Hunter),
	% forward si il peut aller sur la case adjacent sinon tourne pour bien se positionner
	(_{x:X, y:Y} = Case ->
		Action = forward;
		Action = right
	).

% si le gold est déjà dans la poche
action_postGold(Hunter, Case, Direction, Exit, Action) :-
	Direction = [dir{d:Dir, h:hunter{id:hunter}}],
	% si le chasseur est sur la case de sortie : climb sinon choisi l'action
	(Exit = Hunter.c ->
		Action = climb;
		dir_postGold(Hunter, Case, Dir, Action)
	).