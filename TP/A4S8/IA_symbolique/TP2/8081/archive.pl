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