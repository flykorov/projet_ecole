:- module(pos, [trouver_case/3, interface_pit_pos/2, interface_wall_pos/2, interface_wumpus_pos/2, interface_visited_pos/2]).

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

pourtout([], _, NLs, NLs).
pourtout([Case|Ls], Wall, TLs, NLs) :-
	(member(Case, Wall) ->
		pourtout(Ls, Wall, TLs, NLs);
		pourtout(Ls, Wall, [Case|TLs], NLs)
	).

trouver_case(Adjacents, Wall, Ls) :-
	interface_wall_pos(Wall, NWall),
	pourtout(Adjacents, NWall, [], Ls).



interface_visited_pos(Visited, Ls) :-
	visited_pos(Visited, [], Ls).

visited_pos([], NLs, NLs).
visited_pos([X|Ls], TLs, NLs) :-
	X = _{from:OldPos,to:NewPos},
	(member(OldPos, TLs) ->
		visited_pos(Ls, TLs, NLs);
		visited_pos(Ls, [OldPos|TLs], NLs)
	).
