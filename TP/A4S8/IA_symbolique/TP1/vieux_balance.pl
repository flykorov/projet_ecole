
% TP1 - Balancing Chemical Equations
% Auteurs : Victor, Orlane, Geoffrey & Tanguy
% IAD - Groupe 1

% Import des librairies :
:- use_module(library(clpfd)).
:- use_module(library(lists)).
:- use_module(library(pairs)).

% pretraitement des donnees en inversant les Coefficients avec les Ellements.
interface_inverse_key(Ls, NLs) :-
	inverse_key_equ(Ls, [], NLs).

inverse_key_equ([], EKey, EKey).
inverse_key_equ([X|Ls], Acc, EKey) :-
	inverse_key(X, [], NKey),
	flatten(Ls, L),
	inverse_key_equ(L, [NKey|Acc], EKey).

inverse_key(_-[], Nkey, Nkey).
inverse_key(Coef-[Ell-Nb|Ls], Acc, NKey) :-
	inverse_key(Coef-Ls, [Ell-[Coef-Nb]|Acc], NKey).

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
    
    

% Trouve l'equilibre des elements
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

resolution(Coef) :-
	Coef ins 1..1000,
    sum(Coef, #=, S),

   	labeling([min(S)], Coef).

% Regle principale
balance(X, Y) :-
   % Phase de pré-traitement
	avoir_coef(X, Y, Coef),

	interface_elem(X, XLs),
	interface_elem(Y, YLs),

   % Mise en place du systeme d'equation
	equilibre(XLs, YLs),

   % Minimisation des coefficients
	resolution(Coef).
	
% Tests Attendu : 
% Test SANS les Bonus
balance([A-[al-1],B-[o-2]], [C-[al-2,o-3]]).
balance([A-[li-1,fe-1,o-2],B-[h-2,s-1,o-4]],[C-[fe-1,s-1,o-4],D-[li-2,s-1,o-4],E-[h-2,o-1],F-[o-2]]).
balance([A-[li-1,fe-1,p-1,o-4],B-[h-2,s-1,o-4], C-[h-2,o-2]],[D-[fe-1,p-1,o-4],E-[li-2,s-1,o-4],F-[h-2,o-1]]).
balance([A-[li-1,fe-1,o-2],B-[h-1,cl-1]],[C-[fe-1,cl-2],D-[li-1,cl-1],E-[h-2,o-1],F-[cl-2]]).
balance([A-[li-1,co-1,o-2],B-[h-2,s-1,o-4],C-[c-6,h-12,o-6]],[D-[co-1,s-1,o-4],E-[li-2,s-1,o-4],F-[c-1,o-2],G-[h-2,o-1]]).

% Test Bonus :
