:- use_module(library(dicts)).
:- use_module(library(strings)).
:- use_module(reif).
:- use_module(library(clpfd)).
:- use_module(library(http/http_log)).

dir(H, H.certain_fluents.dir).

word("glitter").
word("stench").
word("breeze").

glitter("glitter").
stench("stench").
breeze("breeze").

find_word([]).
find_word([X|Ls]) :-
	text_to_string(X, XC),
	test_if(XC),
	find_word(Ls).

test_if(X) :-
	text_to_string(X, XC),
	(glitter(XC) -> 
		write("glitter"),nl;
	stench(XC) ->
		write("stench"),nl;
	breeze(XC) ->
		write("breeze"),nl
	).



test :-
	Dico = _{ certain_eternals:_{ cells:[ _{x:0,y:0},
					  _{x:1,y:0},
					  _{x:2,y:0},
					  _{x:3,y:0},
					  _{x:4,y:0},
					  _{x:5,y:0},
					  _{x:0,y:1},
					  _{x:1,y:1},
					  _{x:2,y:1},
					  _{x:3,y:1},
					  _{x:4,y:1},
					  _{x:5,y:1},
					  _{x:0,y:2},
					  _{x:1,y:2},
					  _{x:2,y:2},
					  _{x:3,y:2},
					  _{x:4,y:2},
					  _{x:5,y:2},
					  _{x:0,y:3},
					  _{x:1,y:3},
					  _{x:2,y:3},
					  _{x:3,y:3},
					  _{x:4,y:3},
					  _{x:5,y:3},
					  _{x:0,y:4},
					  _{x:1,y:4},
					  _{x:2,y:4},
					  _{x:3,y:4},
					  _{x:4,y:4},
					  _{x:5,y:4},
					  _{x:0,y:5},
					  _{x:1,y:5},
					  _{x:2,y:5},
					  _{x:3,y:5},
					  _{x:4,y:5},
					  _{x:5,y:5}
					],
				  eat_exit:_{c:_{x:1,y:1},e:_{id:exit}},
				  eat_walls:[ _{ c:_{x:5,y:5},
						 w:_{id:wall20}
					       },
					      _{ c:_{x:4,y:5},
						 w:_{id:wall19}
					       },
					      _{ c:_{x:3,y:5},
						 w:_{id:wall18}
					       },
					      _{ c:_{x:2,y:5},
						 w:_{id:wall17}
					       },
					      _{ c:_{x:1,y:5},
						 w:_{id:wall16}
					       },
					      _{ c:_{x:0,y:5},
						 w:_{id:wall15}
					       },
					      _{ c:_{x:5,y:4},
						 w:_{id:wall14}
					       },
					      _{ c:_{x:0,y:4},
						 w:_{id:wall13}
					       },
					      _{ c:_{x:5,y:3},
						 w:_{id:wall12}
					       },
					      _{ c:_{x:0,y:3},
						 w:_{id:wall11}
					       },
					      _{ c:_{x:5,y:2},
						 w:_{id:wall10}
					       },
					      _{ c:_{x:0,y:2},
						 w:_{id:wall9}
					       },
					      _{ c:_{x:5,y:1},
						 w:_{id:wall8}
					       },
					      _{ c:_{x:0,y:1},
						 w:_{id:wall7}
					       },
					      _{ c:_{x:5,y:0},
						 w:_{id:wall6}
					       },
					      _{ c:_{x:4,y:0},
						 w:_{id:wall5}
					       },
					      _{ c:_{x:3,y:0},
						 w:_{id:wall4}
					       },
					      _{ c:_{x:2,y:0},
						 w:_{id:wall3}
					       },
					      _{ c:_{x:1,y:0},
						 w:_{id:wall2}
					       },
					      _{ c:_{x:0,y:0},
						 w:_{id:wall1}
					       }
					    ]
				},
	      certain_fluents:_{ alive:[_{id:hunter}],
				 dir:[_{d:north,h:_{id:hunter}}],
				 fat_gold:[],
				 fat_hunter:_{ c:_{x:1,y:1},
					       h:_{id:hunter}
					     },
				 game_state:running,
				 has_arrow:[ _{ a:_{id:arrow1},
						h:_{id:hunter}
					      }
					   ],
				 has_gold:[],
				 score:0,
				 visited:[]
			       },
	      step:0,
	      uncertain_eternals:_{eat_pit:[],eat_wumpus:[]},
	      uncertain_fluents:_{fatal:[]}
	    },

	dir(Dico, V),

	NewScore = 100,
	write("bou"),

	Dico2 = Dico
		.put(step, NewScore),
	write(Dico2),nl,


	Per = _{ percepts:[breeze,stench] },

	find_word(Per.percepts),
	write(Per.percepts),nl.
