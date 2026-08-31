:- module(adjacent, [adjacent/3]).

:- use_module(library(clpfd)).

adjacent(Ceels, Position, Adjacents) :-
    findall(
        Adjacent,
        (
            member(Adjacent, Ceels),
            (
                Adjacent.x #= Position.x #/\ Adjacent.y #= Position.y + 1
            ) #\/ (
                Adjacent.x #= Position.x #/\ Adjacent.y #= Position.y - 1
            ) #\/ (
                Adjacent.x #= Position.x + 1 #/\ Adjacent.y #= Position.y
            ) #\/ (
                Adjacent.x #= Position.x - 1 #/\ Adjacent.y #= Position.y
            )
        ),
        Adjacents
    ).
