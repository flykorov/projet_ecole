:- module(pos, [trouver_case/3, interface_pit_pos/2, interface_wall_pos/2, interface_wumpus_pos/2, interface_visited_pos/2, trouver_case_pit/3, trouver_case_wumpus/3, trouver_case_visite/3]).

% recupere seulement les positions des murs/pit/wumpus/case adjancent 

interface_wall_pos(Ls, NLs) :-
	wall_pos(Ls, [], NLs).

wall_pos([], NLs, NLs).
wall_pos([X|Ls], NLs, RLs) :-
	X = _{c:Y, w:_{id:_}},
	wall_pos(Ls, [Y|NLs], RLs).

interface_pit_pos(Ls, NLs) :-
	pit_pos(Ls, [], NLs).

pit_pos([], NLs, NLs).
pit_pos([X|Ls], NLs, RLs) :-
	X = _{c:Y, p:_{id:_}},
	pit_pos(Ls, [Y|NLs], RLs).

interface_wumpus_pos(Ls, NLs) :-
	wumpus_pos(Ls, [], NLs).

wumpus_pos([], NLs, NLs).
wumpus_pos([X|Ls], NLs, RLs) :-
	X = _{c:Y, w:_{id:_}},
	wumpus_pos(Ls, [Y|NLs], RLs).


% trouve les walls comme case adjacent du chasseur pour ne pas les rajouter dans la liste des cases qu'il peut traverser

pourtout([], _, NLs, NLs).
pourtout([Case|Ls], Wall, TLs, NLs) :-
	(member(Case, Wall) ->
		pourtout(Ls, Wall, TLs, NLs);
		pourtout(Ls, Wall, [Case|TLs], NLs)
	).

trouver_case(Adjacents, Wall, Ls) :-
	interface_wall_pos(Wall, NWall),
	pourtout(Adjacents, NWall, [], Ls).


% Visited :
interface_visited_pos(Visited, Ls) :-
	visited_pos(Visited, [], Ls).

visited_pos([], NLs, NLs).
visited_pos([X|Ls], TLs, NLs) :-
	X = _{from:OldPos,to:NewPos},
	(member(OldPos, TLs) ->
		visited_pos(Ls, TLs, NLs);
		visited_pos(Ls, [OldPos|TLs], NLs)
	).

% Trouver les pits :
interface_recup_pit(Ls, NLs) :-
	recup_pit(Ls, [], NLs).

recup_pit([], NLs, NLs).
recup_pit([X|Ls], NLs, RLs) :-
	X = _{c:Y, p:_{id:Z}},

	% On garde que les Z=true (les vrai pits) :
	(Z = true -> 
		recup_pit(Ls, [Y|NLs], RLs);  % Si c'est un "vrai pit" on le rajoute a la liste
		recup_pit(Ls, [[]|NLs], RLs) % Sinon on ne l'ajoute pas
	).


	%recup_pit(Ls, [Y|NLs], RLs).


trouver_case_pit(Adjacents, Pits, Ls) :-
	interface_recup_pit(Pits, NPits),
	pourtout(Adjacents, NPits, [], Ls).

% Trouver les wumpus : 
interface_recup_wumpus(Ls, NLs) :-
	recup_wumpus(Ls, [], NLs).

recup_wumpus([], NLs, NLs).
recup_wumpus([X|Ls], NLs, RLs) :-
	X = _{c:Y, w:_{id:Z}},

	% On garde que les Z=true (les vrai pits) :
	(Z = true -> 
		% Si c'est un "vrai pit" on le rajoute a la liste Sinon on ne l'ajoute pas 
		recup_wumpus(Ls, [Y|NLs], RLs);
		recup_wumpus(Ls, [[]|NLs], RLs) 

	).


	%recup_pit(Ls, [Y|NLs], RLs).


trouver_case_wumpus(Adjacents, Wumpus, Ls) :-
	interface_recup_wumpus(Wumpus, NWumpus),
	pourtout(Adjacents, NWumpus, [], Ls).


% Visite

trouver_case_visite(Adjacent, [], Adjacent).
trouver_case_visite(Adjacent, Visite, Ls) :-
	pourtout(Adjacent, Visite, [], LTs),

	% Si la liste est vide, on autorise de revenir sur une case déjà visiter
	(LTs = [] -> 
		Ls = Adjacent;  
		Ls = LTs 		
	).