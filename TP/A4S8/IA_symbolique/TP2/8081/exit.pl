:- module(exit, [exit/5]).

:- use_module(pos).
:- use_module(adjacent).
	
trouver_adjacent([], _, _, _, _).
trouver_adjacent([X|Adjacents], Visited, Chasseur, Cells, Case) :-
	
	(member(X, Visited) ->
		delete(Visited, X, V),
		trouver_chemin(X, V, Chasseur, Cells, Case);
		http_log('Completion du else : ~w\n', [X])
	),
	trouver_adjacent(Adjacents, Visited, Chasseur, Cells, Case).

stop_chemin(X, X).
trouver_chemin(Depart, Visited, Chasseur, Cells, Case) :-
	adjacent(Cells, Depart, Adjacents),

	(member(Chasseur, Adjacents) ->
		stop_chemin(Depart, Case);
		trouver_adjacent(Adjacents, Visited, Chasseur, Cells, Case)
	).

exit(Sortie, Visited, Chasseur, Cells, Case) :-
	interface_visited_pos(Visited, Ls),

	trouver_chemin(Sortie, Ls, Chasseur, Cells, Case).


affecter_case([X|Ls], X).
remonter_chemin(Depart, Visited, Case) :-
	interface_visited_pos(Visited, Ls),
	affecter_case(Ls).