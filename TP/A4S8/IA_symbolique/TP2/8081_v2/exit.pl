:- module(exit, [remonter_chemin/2]).


% choisi la derniere case visiter par le chasseur
% reviens par là où il est passé

remonter_chemin([], _{x:1, y:1}).
remonter_chemin([_{from:X, to:_}|_], X).
