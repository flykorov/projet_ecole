faux_pit(false, X, Ls, [X|Ls]).
faux_pit(true, _, Ls, Ls).

find_no_pit([], NLs, NLs).
find_no_pit([X|Ls], TLs, NLs) :-
	X = _{c:Y, p:_{id:Id}},
	faux_pit(Id, Y, TLs, RLs),
	find_no_pit(Ls, RLs, NLs).


vrai_pit(true, X, Ls, [X|Ls]).
vrai_pit(false, _, Ls, Ls).

find_pit([], NLs, NLs).
find_pit([X|Ls], TLs, NLs) :-
	X = _{c:Y, p:_{id:Id}},
	vrai_pit(Id, Y, TLs, RLs),
	find_pit(Ls, RLs, NLs).

	forall(
		member(Case, Adjacents),
		(member(Case, NWall) ->
			http_log('walls : ~w\n', [Case]);
			ajouter(Case, Ls, Ls),
			http_log('NLs : ~w\n', [Ls]),
			append([], NLs, Ls)
		)
	).

trouver_adjacent([], _, _, _, _).
trouver_adjacent([X|Adjacents], Visited, Chasseur, Cells, Case) :-
	http_log('La valeur de Adjacents est : ~w\n', [Adjacents]),
	
	(member(X, Visited) ->
		delete(Visited, X, V),
		http_log('La valeur de X est : ~w\n', [X]),
		http_log('La valeur de V est : ~w\n', [V]),
		trouver_chemin(X, V, Chasseur, Cells, Case);
		http_log('Completion du else : ~w\n', [X])
	),
	http_log('La valeur de Visited est : ~w\n', [Visited]),
	trouver_adjacent(Adjacents, Visited, Chasseur, Cells, Case).

stop_chemin(X, X).
trouver_chemin(Depart, Visited, Chasseur, Cells, Case) :-
	adjacent(Cells, Depart, Adjacents),
	http_log('La valeur de Adjacents est : ~w\n', [Adjacents]),

	(member(Chasseur, Adjacents) ->
		http_log('La valeur de Depart est : ~w\n', [Depart]),
		stop_chemin(Depart, Case),
		http_log('La valeur de Case est : ~w\n', [Case]);
		trouver_adjacent(Adjacents, Visited, Chasseur, Cells, Case)
	).

exit(Sortie, Visited, Chasseur, Cells, Case) :-
	interface_visited_pos(Visited, Ls),
	http_log('La valeur de Ls est : ~w\n', [Ls]),

	trouver_chemin(Sortie, Ls, Chasseur, Cells, Case).
