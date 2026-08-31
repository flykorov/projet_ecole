:- module(arrow, [updateHasArrow/3]).

updateHasArrow(shoot, Certain_Fluents, New_Certain_Fluents) :-
	New_Certain_Fluents = Certain_Fluents.put(has_arrow, false).


updateHasArrow(grab, Certain_Fluents, Certain_Fluents).
updateHasArrow(forward, Certain_Fluents, Certain_Fluents).
updateHasArrow(right, Certain_Fluents, Certain_Fluents).
updateHasArrow(left, Certain_Fluents, Certain_Fluents).
updateHasArrow(climb, Certain_Fluents, Certain_Fluents).