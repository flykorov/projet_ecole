% TP1 IA Symbolique
% Tanguy Valin, Orlane Gruet, Geoffroy Rodriguez, Victor Bouvier d'Acher

:- use_module(library(clpfd)).
:- use_module(library(lists)).
:- use_module(library(pairs)).

% pretraitement des donnees en inversant les Coef avec les Ell.

interface_inverse_key(Ls, NLs) :-
	inverse_key_equ(Ls, [], NLs).

inverse_key_equ([], EKey, EKey).
inverse_key_equ([X|Ls], Acc, EKey) :-
	interface_pretraitement(X, NX),
	inverse_key(NX, [], NKey),
	flatten(Ls, L),
	inverse_key_equ(L, [NKey|Acc], EKey).

inverse_key(_-[], Nkey, Nkey).
inverse_key(Coef-[Ell-Nb|Ls], Acc, NKey) :-
	inverse_key(Coef-Ls, [Ell-[Coef-Nb]|Acc], NKey).

divise_ell([], _, NLs, NLs).
divise_ell(E, Nb, _, E-Nb).
divise_ell([K-V|Ls], Nb, Acc, NLs) :-
	Mul #= Nb*V,
	divise_ell(Ls, Nb, [K-Mul|Acc], NLs).

interface_ajout(Ls, CLs, NLs):-
	ajout_list(Ls, CLs, NLs).

ajout_list([], NLs, NLs).
ajout_list(K-V, Acc, [K-V|Acc]).
ajout_list([X|Ls], Acc, NLs) :-
	ajout_list(Ls, [X|Acc], NLs).

interface_pretraitement(Coef-Ls, Coef-NLs) :-
	list_pretraitement(Ls, [], NLs).

list_pretraitement([], Nkey, Nkey).
list_pretraitement([Ell-Nb|Ls], Acc, NKey) :- 
	divise_ell(Ell, Nb, [], NLs),
	interface_ajout(NLs, Acc, NNLs),
	list_pretraitement(Ls, NNLs, NKey).


% donne les elements ordonne avec leurs coef

interface_elem(Ls, NLs) :-
	interface_inverse_key(Ls, PLs),
	flatten(PLs, PPls),
	sort(1, @>=, PPls, PPPLs),
	group_pairs_by_key(PPPLs, NLs).


res_equation(_-XLs, _-YLs) :-
	flatten(XLs, X),
	pairs_keys_values(X, XKs, XVs),
	flatten(YLs, Y),
	pairs_keys_values(Y, YKs, YVs),

    % Mise en place de la contrainte :
    % Contrainte sous la forme : XKs.XVs = YKs.YVs (produit scalaire)
    scalar_product(XVs, XKs, #=, Cg),
    scalar_product(YVs, YKs, #=, Cd),

    Cg #= Cd.
   

% trouve l'equilibre des elements

equilibre([], []).
equilibre([X|XLs], [Y|YLs]) :-

	res_equation(X, Y),
	equilibre(XLs, YLs).
	

avoir_clef([], RLs, RLs).
avoir_clef([X-_|Ls], Acc, RLs) :-
	avoir_clef(Ls, [X|Acc], RLs).

avoir_coef(X, Y, Coef) :-
	avoir_clef(X, [], KX),
	avoir_clef(Y, [], KY),

	append(KX, KY, Coef).

% resout l'equation en donnant les coefficients minimal possible

resolution(Coef) :-
	Coef ins 1..1000,
    sum(Coef, #=, S),

   	labeling([min(S)], Coef).

% fonction main

balance(X, Y) :-

	avoir_coef(X, Y, Coef),

	interface_elem(X, XLs),
	interface_elem(Y, YLs),

	equilibre(XLs, YLs),

	resolution(Coef).


% les 8 tests d'equation

test1 :-
	write('[A-[al-1],B-[o-2]], [C-[al-2,o-3]]'),nl,

	balance([A-[al-1],B-[o-2]], [C-[al-2,o-3]]),

	write('A = '),write(A),
	write(', B = '),write(B),
	write(', C = '),write(C),
	write('.'),nl,nl.

test2 :-
	write('[A-[c-4,h-10],B-[o-2]], [C-[c-1,o-2],D-[h-2,o-1]]'),nl,

	balance([A-[c-4,h-10],B-[o-2]], [C-[c-1,o-2],D-[h-2,o-1]]),

	write('A = '),write(A),
	write(', B = '),write(B),
	write(', C = '),write(C),
	write(', D = '),write(D),
	write('.'),nl,nl.

test3 :-
	write('[A-[li-1,fe-1,o-2],B-[h-2,s-1,o-4]],[C-[fe-1,s-1,o-4],D-[li-2,s-1,o-4],E-[h-2,o-1],F-[o-2]]'),nl,

	balance([A-[li-1,fe-1,o-2],B-[h-2,s-1,o-4]],[C-[fe-1,s-1,o-4],D-[li-2,s-1,o-4],E-[h-2,o-1],F-[o-2]]),

	write('A = '),write(A),
	write(', B = '),write(B),
	write(', C = '),write(C),
	write(', D = '),write(D),
	write(', E = '),write(E),
	write(', F = '),write(F),
	write('.'),nl,nl.

test4 :-
	write('[A-[li-1,fe-1,p-1,o-4],B-[h-2,s-1,o-4], C-[h-2,o-2]],[D-[fe-1,p-1,o-4],E-[li-2,s-1,o-4],F-[h-2,o-1]]'),nl,

	balance([A-[li-1,fe-1,p-1,o-4],B-[h-2,s-1,o-4], C-[h-2,o-2]],[D-[fe-1,p-1,o-4],E-[li-2,s-1,o-4],F-[h-2,o-1]]),

	write('A = '),write(A),
	write(', B = '),write(B),
	write(', C = '),write(C),
	write(', D = '),write(D),
	write(', E = '),write(E),
	write(', F = '),write(F),
	write('.'),nl,nl.

test5 :-
	write('[A-[li-1,fe-1,o-2],B-[h-1,cl-1]],[C-[fe-1,cl-2],D-[li-1,cl-1],E-[h-2,o-1],F-[cl-2]]'),nl,

	balance([A-[li-1,fe-1,o-2],B-[h-1,cl-1]],[C-[fe-1,cl-2],D-[li-1,cl-1],E-[h-2,o-1],F-[cl-2]]),

	write('A = '),write(A),
	write(', B = '),write(B),
	write(', C = '),write(C),
	write(', D = '),write(D),
	write(', E = '),write(E),
	write(', F = '),write(F),
	write('.'),nl,nl.

test6 :-
	write('[A-[li-1,co-1,o-2],B-[h-2,s-1,o-4],C-[c-6,h-12,o-6]],[D-[co-1,s-1,o-4],E_-[li-2,s-1,o-4],F-[c-1,o-2],G-[h-2,o-1]]'),nl,

	balance([A-[li-1,co-1,o-2],B-[h-2,s-1,o-4],C-[c-6,h-12,o-6]],[D-[co-1,s-1,o-4],E-[li-2,s-1,o-4],F-[c-1,o-2],G-[h-2,o-1]]),

	write('A = '),write(A),
	write(', B = '),write(B),
	write(', C = '),write(C),
	write(', D = '),write(D),
	write(', E = '),write(E),
	write(', F = '),write(F),
	write(', G = '),write(G),
	write('.'),nl,nl.

test7 :-
	write('[A-[li-1,fe-1,o-2],B-[h-1,n-1,o-3]],[C-[fe-1,[n-1,o-3]-2],D-[li-1,n-1,o-3],E-[h-2,o-1],F-[o-2]]'),nl,

	balance([A-[li-1,fe-1,o-2],B-[h-1,n-1,o-3]],[C-[fe-1,[n-1,o-3]-2],D-[li-1,n-1,o-3],E-[h-2,o-1],F-[o-2]]),

	write('A = '),write(A),
	write(', B = '),write(B),
	write(', C = '),write(C),
	write(', D = '),write(D),
	write(', E = '),write(E),
	write(', F = '),write(F),
	write('.'),nl,nl.

test8 :-
	write('[A-[li-1,fe-1,o-2],B-[h-1,c-1,o-1,o-1,h-1],C-[h-2,o-2]],[D-[fe-1,[c-1,o-1,o-1,h-1]-2],E-[li-1,c-1,o-1,o-1,h-1],F-[h-2,o-1],G-[o-2]]'),nl,

	balance([A-[li-1,fe-1,o-2],B-[h-1,c-1,o-1,o-1,h-1],C-[h-2,o-2]],[D-[fe-1,[c-1,o-1,o-1,h-1]-2],E-[li-1,c-1,o-1,o-1,h-1],F-[h-2,o-1],G-[o-2]]),

	write('A = '),write(A),
	write(', B = '),write(B),
	write(', C = '),write(C),
	write(', D = '),write(D),
	write(', E = '),write(E),
	write(', F = '),write(F),
	write(', G = '),write(G),
	write('.'),nl,nl.

% lancer les 8 tests

test :-
	test1,
	test2,
	test3,
	test4,
	test5,
	test6,
	test7,
	test8.
