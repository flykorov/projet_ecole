:- module(has_gold, [updateHasGold/4]).

% Mise à jour du gold :
goldMaj(Certain_Fluents, New_Certain_Fluents) :-
    New_Certain_Fluents = Certain_Fluents.put(has_gold, true).

updateHasGold(grab, [], Certain_Fluents, Certain_Fluents). % Si on ne perçoit rien, on ne met pas à jour le gold
updateHasGold(grab, Percepts ,Certain_Fluents, New_Certain_Fluents) :-
    % Si l'action séléctionner est grab et que l'on détécte bien 'glitter', on obtien le gold
    (member(glitter, Percepts) ->
        goldMaj(Certain_Fluents, New_Certain_Fluents);
        New_Certain_Fluents = Certain_Fluents
    ).
    
% Pour toutes les autres actions, on n'obtien pas le gold
updateHasGold(left, _, Certain_Fluents, Certain_Fluents).
updateHasGold(right, _, Certain_Fluents, Certain_Fluents).
updateHasGold(forward, _, Certain_Fluents, Certain_Fluents).
updateHasGold(climb, _, Certain_Fluents, Certain_Fluents).
updateHasGold(shoot, _, Certain_Fluents, Certain_Fluents).