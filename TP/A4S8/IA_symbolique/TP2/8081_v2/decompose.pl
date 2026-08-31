:- module(decompose, [certain_fluents/2]).

certain_fluents(H, H.certain_fluents).
certain_eternals(H, H.certain_eternals).
step(H, H.step).
uncertain_eternals(H, H.uncertain_eternals).
uncertain_fluents(H, H.uncertain_fluents).

% interieur de certain_eternals

cells(H, H.certain_eternals.cells).
eat_exit(H, H.certain_eternals.eat_exit).
eat_walls(H, H.eat_walls).


% interieur de certain_fluents

alive(H, H.certain_fluents.alive).
dir(H, H.certain_fluents.dir).
fat_gold(H, H.certain_fluents.fat_gold).
fat_hunter(H, H.certain_fluents.fat_hunter).
game_state(H, H.certain_fluents.game_state).
has_arrow(H, H.certain_fluents.has_arrow).
has_gold(H, H.certain_fluents.has_gold).
score(H, H.certain_fluents.score).
visited(H, H.certain_fluents.visited).

