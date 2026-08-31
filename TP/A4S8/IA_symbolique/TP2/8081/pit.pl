:- module(pit, [updateEatPit/6]).

:- use_module(pos).
:- use_module(library(lists)).

interface_tab_etat(Ls, TLs, FLs) :-
	tab_etat(Ls, [], TLs, [], FLs).

tab_etat([], TLs, TLs, FLs, FLs).
tab_etat([X|Ls], TTLs, TLs, TFLs, FLs) :-
	X = _{c:Y, p:_{id:Id}},
	(vrai(Id) ->
		tab_etat(Ls, [Y|TTLs], TLs, TFLs, FLs);
		tab_etat(Ls, TTLs, TLs, [Y|TFLs], FLs)
	).

vrai(true).
faux(false).

true_add_true([], _, NULs, NULs).
true_add_true([X|Ls], PLs, RLs, NULs) :-
	(member(X, PLs) ->
		true_add_true(Ls, PLs, RLs, NULs);
		true_add_true(Ls, PLs, [_{c:X, p:_{id:true}}|RLs], NULs)
	).

true_add_false([], NULs, NULs).
true_add_false([X|Ls], RLs, NULs) :-
	true_add_false(Ls, [_{c:X, p:_{id:false}}|RLs], NULs).

verif_true_on_false([], _, NLs, NLs).
verif_true_on_false([X|Ls], FLs, RLs, NLs) :-
	(member(X, FLs) ->
		verif_true_on_false(Ls, FLs, RLs, NLs);
		verif_true_on_false(Ls, FLs, [_{c:X, p:_{id:true}}|RLs], NLs)
	).

all_true([], NLs, NLs).
all_true([X|Ls], TLs, NLs) :-
	(member(X, TLs) ->
		all_true(Ls, TLs, NLs);
		all_true(Ls, [X|TLs], NLs)
	).

tab_true(Ls, TLs, FLs, TotalLs) :-
	true_add_false(FLs, [], NFLs),
	interface_pit_pos(NFLs, PFLs),
	all_true(Ls, TLs, NTLs),
	true_add_true(NTLs, PFLs, [], TTLs),
	interface_pit_pos(TTLs, PTLs),
	verif_true_on_false(PTLs, PFLs, [], NTLs),
	append(NTLs, NFLs, TotalLs).

true_pit(Ls, ULs, NULs) :-
	interface_tab_etat(ULs, TLs, FLs),
	tab_true(Ls, TLs, FLs, NULs).

false_add_true([], _, NULs, NULs).
false_add_true([X|Ls], PLs, RLs, NULs) :-
	(member(X, PLs) ->
		false_add_true(Ls, PLs, RLs, NULs);
		false_add_true(Ls, PLs, [_{c:X, p:_{id:true}}|RLs], NULs)
	).

add_pred_false([], NFLs, NFLs).
add_pred_false([X|Ls], FLs, NFLs) :-
	add_pred_false(Ls, [_{c:X, p:_{id:false}}|FLs], NFLs).

false_add_false([], _, NULs, NULs).
false_add_false([X|Ls], PLs, RLs, NULs) :-
	(member(X, PLs) ->
		false_add_false(Ls, PLs, RLs, NULs);
		false_add_false(Ls, PLs, [_{c:X, p:_{id:false}}|RLs], NULs)
	).

tab_false(Ls, TLs, FLs, TotalLs) :-
	false_add_false(Ls, FLs, [], NFLs),
	interface_pit_pos(NFLs, PFLs),
	false_add_true(TLs, PFLs, [], NTLs),
	append(NTLs, NFLs, TotalLs).

false_pit(Ls, Hunter, ULs, NULs) :-
	interface_tab_etat(ULs, TLs, FLs),
	(member(Hunter, FLs) ->
		tab_false(Ls, TLs, FLs, NULs);
		tab_false(Ls, TLs, [Hunter|FLs], NULs)
	).

updateEatPit(Percept, Hunter, Adjacents, Wall, Uncertain_Eternals, New_Uncertain_Eternals) :-
	trouver_case(Adjacents, Wall, Ls),

	(member(breeze, Percept) ->
		true_pit(Ls, Uncertain_Eternals.eat_pit, NLs);
		false_pit(Ls, Hunter, Uncertain_Eternals.eat_pit, NLs)
	),
	New_Uncertain_Eternals = Uncertain_Eternals.put(eat_pit, NLs).
