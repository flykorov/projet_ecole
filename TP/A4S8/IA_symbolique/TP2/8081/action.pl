


setXY(north, X, Y, Fat_hunter) :- 
	X #= Fat_hunter.c.x,
	Y #= Fat_hunter.c.y + 1.

setXY(south, X, Y, Fat_hunter) :- 
	X #= Fat_hunter.c.x,
	Y #= Fat_hunter.c.y - 1.

setXY(east, X, Y, Fat_hunter) :- 
	X #= Fat_hunter.c.x + 1,
	Y #= Fat_hunter.c.y.

setXY(west, X, Y, Fat_hunter) :- 
	X #= Fat_hunter.c.x - 1,
	Y #= Fat_hunter.c.y.

dir_postGold(Hunter, Case, Dir, Action) :-
	setXY(Dir, X, Y, Hunter),
	(_{x:X, y:Y} = Case ->
		Action = forward;
		Action = right
	).

action_postGold(Hunter, Case, Dir, Exit, Action) :-
	(Exit = Hunter ->
		Action = climb;
		dir_postGold(Hunter, Case, Dir, Action)
	).