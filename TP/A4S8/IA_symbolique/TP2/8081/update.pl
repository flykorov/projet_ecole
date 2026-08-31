:- module(update, [calculer_action_croyances/4]).

:- use_module(library(http/http_json)).
:- use_module(library(clpfd)).

:- use_module(direction).
:- use_module(visited).
:- use_module(pit).
:- use_module(wumpus).
:- use_module(adjacent).
:- use_module(exit).

:- use_module(decompose).


word("glitter").
word("stench").
word("breeze").

find_word([]).
find_word([X|Ls]) :-
	text_to_string(X, XC),
	word(XC),
	find_word(Ls).


calculer_action_croyances(HunterBeliefs, Percepts, NewBeliefs, Action) :-
	Hunter = _{ c:_{x:2,y:2},
					   h:_{id:hunter}
					 },

	Visited = [  _{from:_{x:2,y:2},to:_{x:2,y:3}},
			  _{from:_{x:2,y:1},to:_{x:2,y:2}},
			  _{from:_{x:1,y:1},to:_{x:2,y:1}},
			  _{from:_{x:1,y:2},to:_{x:1,y:1}},
			  _{from:_{x:1,y:1},to:_{x:1,y:2}}
				   ],

	NewBeliefs = HunterBeliefs.put(certain_fluents/fat_hunter, Hunter)
							  .put(certain_fluents/visited, Visited),
	
    remonter_chemin(Depart, Visited, Case),
    

    .

%	certain_fluents(HunterBeliefs, Certain_Fluents),

%	updateDir(left, Certain_Fluents, New_dir),

%	updateVisited(forward, New_dir, New_visited),

%	NewBeliefs = HunterBeliefs.put(certain_fluents, New_visited),
