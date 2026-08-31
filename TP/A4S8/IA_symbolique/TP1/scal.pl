:- use_module(library(clpfd)).
:- use_module(library(lists)).
:- use_module(library(pairs)).

caaall(X, Y) :-
    X + Y #= 5,
    X #> 0,
    Y #> 0,
    
    Vars = [X, Y],
    
    % Utilisation de labeling pour trouver une solution
    labeling([enum], Vars).