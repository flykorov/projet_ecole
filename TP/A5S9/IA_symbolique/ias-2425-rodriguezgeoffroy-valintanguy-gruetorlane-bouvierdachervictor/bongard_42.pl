% Empty with aleph loaded
:- use_module(library(aleph)).
:- aleph.

:- modeh(*, left(+img)).

:- modeb(*, contains(+img,[-fig|-figs])).
:- modeb(*, in(+fig,[-fig, -fig, -fig])).
:- modeb(*, aligned(+fig, +fig, +fig)). 

:- determination(left/1,contains/2).
:- determination(left/1,in/2).
:- determination(left/1,aligned/3).

% left(I) :- contains(I, [LF | _]), in(LF, [F1, F2, F3]), aligned(F1, F2, F3). 

:- aleph_set(i,10).

:- aleph_set(verbosity,10).

:-begin_bg.


fig(F) :- ellipse(F).
fig(F) :- circle(F).
fig(F) :- blob(F).
fig(F) :- triangle(F).
fig(F) :- rectangle(F).


figs([]).
figs([Fh|Ft]) :- fig(Fh), figs(Ft).


aligned(F1, F2, F3) :-
    position(F1, X1, Y1),
    position(F2, X2, Y2),
    position(F3, X3, Y3),
    Det is X1 * (Y2 - Y3) + X2 * (Y3 - Y1) + X3 * (Y1 - Y2),
    Det =:= 0.
% pos

img(i11).
blob(b11).
circle(c11a).
circle(c11b).
circle(c11c).
circle(c11d).
contains(i11, [b11, c11a]).
in(b11, [c11b, c11c, c11d]).
position(c11a, 4, 1).
position(c11b, 1, 1).
position(c11c, 2, 2).
position(c11d, 3, 3).

img(i12).
triangle(t12).
circle(c12a).
circle(c12b).
circle(c12c).
circle(c12d).
circle(c12e).
contains(i12, [t12, c12a, c12b]).
in(t12, [c12c, c12d, c12e]).
position(c12a, 1, 1).
position(c12b, 3, 2).
position(c12c, 4, 4).
position(c12d, 4, 3).
position(c12e, 4, 1).

img(i21).
rectangle(r21).
circle(c21a).
circle(c21b).
circle(c21c).
circle(c21d).
contains(i21, [r21, c21a]).
in(r21, [c21b, c21c, c21d]).
position(c21a, 4, 1).
position(c21b, 1, 3).
position(c21c, 2, 3).
position(c21d, 3, 3).



img(i22).
ellipse(e22).
circle(c22a).
circle(c22b).
circle(c22c).
circle(c22d).
circle(c22e).
contains(i22, [e22, c22a, c22b]).
in(e22, [c22c, c22d, c22e]).
position(c22a, 1, 1).
position(c22b, 3, 2).
position(c22c, 2, 4).
position(c22d, 1, 3).
position(c22e, 3, 5).



img(i31).
blob(b31).
circle(c31a).
circle(c31b).
circle(c31c).
circle(c31d).
circle(c31e).
contains(i31, [b31, c31a, c31b]).
in(b31, [c31c, c31d, c31e]).
position(c31a, 1, 1).
position(c31b, 3, 2).
position(c31c, 4, 2).
position(c31d, 5, 3).
position(c31e, 6, 4).


img(i32).
circle(c32a).
circle(c32b).
circle(c32c).
circle(c32d).
circle(c32e).
contains(i32, [c32a, c32b]).
in(c32a, [c32c, c32d, c32e]).
position(c32a, 1, 1).
position(c32b, 3, 2).
position(c32c, 1, 2).
position(c32d, 1, 3).
position(c32e, 1, 4).



% neg

img(i13).
triangle(t13).
circle(c13a).
circle(c13b).
circle(c13c).
circle(c13d).
circle(c13e).
contains(i13, [t13, c13a, c13b]).
in(t13, [c13c, c13d, c13e]).
position(c13a, 1, 1).
position(c13b, 3, 2).
position(c13c, 1, 2).
position(c13d, 1, 3).
position(c13e, 5, 4).


img(i14).
blob(b14).
circle(c14a).
circle(c14b).
circle(c14c).
circle(c14d).
circle(c14e).
contains(i14, [b14, c14a, c14b]).
in(b14, [c14c, c14d, c14e]).
position(c14a, 1, 1).
position(c14b, 3, 2).
position(c14c, 2, 2).
position(c14d, 5, 2).
position(c14e, 5, 4).


img(i23).
circle(c23a).
circle(c23b).
circle(c23c).
circle(c23d).
circle(c23e).
circle(c23f).
contains(i23, [c23a, c23b, c23c]).
in(c23a, [c23d, c23e, c23f]).
position(c23a, 1, 1).
position(c23b, 3, 2).
position(c23c, 2, 2).
position(c23d, 6, 1).
position(c23e, 1, 4).
position(c23f, 2, 6).

img(i24).
blob(b24).
circle(c24a).
circle(c24b).
circle(c24c).
circle(c24d).
contains(i24, [b24, c24a]).
in(b24, [c24b, c24c, c24d]).
position(c24a, 1, 1).
position(c24b, 1, 2).
position(c24c, 5, 5).
position(c24d, 6, 1).


img(i33).
rectangle(r33).
circle(c33a).
circle(c33b).
circle(c33c).
circle(c33d).
circle(c33e).
contains(i33, [r33, c33a, c33b]).
in(r33, [c33c, c33d, c33e]).
position(c33a, 1, 3).
position(c33b, 2, 2).
position(c33c, 5, 5).
position(c33d, 1, 8).
position(c33e, 2, 4).

img(i34).
rectangle(r34).
circle(c34a).
circle(c34b).
circle(c34c).
circle(c34d).
contains(i34, [r34, c34a]).
in(r34, [c34b, c34c, c34d]).
position(c34a, 1, 3).
position(c34b, 5, 2).
position(c34c, 1, 9).
position(c34d, 5, 8).

% pos non vu

img(i90).
triangle(t90).
circle(c90a).
circle(c90b).
circle(c90c).
circle(c90d).
contains(i90, [t90, c90a]).
in(t90, [c90b, c90c, c90d]).
position(c90a, 8, 1).
position(c90b, 1, 2).
position(c90c, 1, 4).
position(c90d, 1, 5).

img(i91).
rectangle(r91).
circle(c91a).
circle(c91b).
circle(c91c).
circle(c91d).
circle(c91e).
contains(i91, [r91, c91a, c91b]).
in(r91, [c91c, c91d, c91e]).
position(c91a, 4, 1).
position(c91b, 1, 3).
position(c91c, 5, 4).
position(c91d, 4, 3).
position(c91e, 3, 2).

img(i92).
rectangle(r92).
circle(c92a).
circle(c92b).
circle(c92c).
contains(i92, [r92]).
in(r92, [c92a, c92b, c92c]).
position(c92a, 1, 3).
position(c92b, 2, 4).
position(c92c, 5, 7).

img(i93).
blob(b93).
circle(c93a).
circle(c93b).
circle(c93c).
contains(i93, [b93]).
in(b93, [c93a, c93b, c93c]).
position(c93a, 1, 1).
position(c93b, 2, 2).
position(c93c, 5, 5).

img(i94).
circle(c94a).
circle(c94b).
circle(c94c).
circle(c94d).
circle(c94e).
contains(i94, [c94a, c94b]).
in(c94a, [c94c, c94d, c94e]).
position(c94a, 1, 5).
position(c94b, 3, 4).
position(c94c, 2, 2).
position(c94d, 4, 2).
position(c94e, 5, 2).

% neg non vu

img(i95).
circle(c95a).
circle(c95b).
circle(c95c).
circle(c95d).
contains(i95, [c95a]).
in(c95a, [c95b, c95c, c95d]).
position(c95a, 8, 8).
position(c95b, 3, 4).
position(c95c, 5, 5).
position(c95d, 3, 9).

img(i96).
blob(b96).
circle(c96a).
circle(c96b).
circle(c96c).
circle(c96d).
circle(c96e).
contains(i96, [b96, c96a, c96b]).
in(b96, [c96c, c96d, c96e]).
position(c96a, 1, 8).
position(c96b, 5, 2).
position(c96c, 5, 5).
position(c96d, 6, 1).
position(c96d, 8, 1).

img(i97).
rectangle(r97).
circle(c97a).
circle(c97b).
circle(c97c).
contains(i97, [r97]).
in(r97, [c97a, c97b, c97c]).
position(c97a, 1, 6).
position(c97b, 5, 4).
position(c97c, 5, 9).

img(i98).
triangle(t98).
circle(c98a).
circle(c98b).
circle(c98c).
circle(c98d).
contains(i98, [t98, c98a]).
in(t98, [c98b, c98c, c98d]).
position(c98a, 5, 1).
position(c98b, 3, 3).
position(c98c, 1, 5).
position(c98d, 5, 3).

img(i99).
triangle(t99).
circle(c99a).
circle(c99b).
circle(c99c).
contains(i99, [t99]).
in(t99, [c99a, c99b, c99c]).
position(c99a, 1, 1).
position(c99b, 3, 4).
position(c99c, 1, 8).


:- end_bg.

:-begin_in_pos.

left(i11).
left(i12).
left(i21).
left(i22).
left(i31).
left(i32).

:-end_in_pos.

:-begin_in_neg.

left(i13).
left(i14).
left(i23).
left(i24).
left(i33).
left(i34).

:-end_in_neg.

:-aleph_read_all.

check_none_seen_figure :-
    left(i90),
    left(i91),
    left(i92),
    left(i93),
    left(i94),
    \+ left(i95),
    \+ left(i96),
    \+ left(i97),
    \+ left(i98),
    \+ left(i99).


/** <examples> Your example queries go here, e.g.

?- induce(Program).

*/
