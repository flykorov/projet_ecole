% Empty with aleph loaded
:- use_module(library(aleph)).

:- aleph.

:- modeh(*, left(+img)).

:- modeb(*, sep(+img,-fig)).
:- modeb(*, down(+fig, -figs)).
:- modeb(*, verif(+figs)).

:- determination(left/1,sep/2).
:- determination(left/1,down/2).
:- determination(left/1,verif/1).

% left(I) :- sep(I, L), down(L, F), verif(F).

:- aleph_set(i,10).

:- aleph_set(verbosity,10).


:-begin_bg.

fig(F) :- v(F).
fig(F) :- a(F).
fig(F) :- circle(F).
fig(F) :- triangle(F).
fig(F) :- rectangle(F).
fig(F) :- ligne(F).
fig(F) :- blank(F).

figs([]).
figs([Fh|Ft]) :- fig(Fh), figs(Ft).

verif([]).
verif([F|Ls]) :- 
    cor(F, Va, Av),
	res(Va, Av, Ans),
    (   
    	is_circle(Ans), circle(F);
    	is_rectangle(Ans), rectangle(F);
		is_triangle(Ans), triangle(F);
    	is_blank(Ans), blank(F)
    ),
    verif(Ls).

is_circle(vv).
is_rectangle(va).
is_triangle(aa).
is_blank(av).

img(i11).
v(v11a).
v(v11b).
v(v11c).
a(a11).
ligne(l11).
circle(c11).
rectangle(r11).
sep(i11, l11).
up(l11, [v11a, v11b, v11c, a11]).
down(l11, [c11, r11]).
cor(c11, v11a, v11b).
cor(r11, v11c, a11).
res(v11a, v11b, vv).
res(v11c, a11, va).

img(i12).
a(a12a).
v(v12).
a(a12b).
a(a12c).
ligne(l12).
blank(b12).
triangle(t12).
sep(i12, l12).
up(l12, [a12a, v12, a12b, a12c]).
down(l12, [b12, t12]).
cor(b12, a12a, v12).
cor(t12, a12b, a12c).
res(a12a, v12, av).
res(a12b, a12c, aa).

img(i21).
a(a21a).
v(v21a).
a(a21b).
v(v21b).
ligne(l21).
blank(b21a).
blank(b21b).
sep(i21, l21).
up(l21, [a21a, v21a, a21b, v21b]).
down(l21, [b21a, b21b]).
cor(b21a, a21a, v21a).
cor(b21b, a21b, v21b).
res(a21a, v21a, av).
res(a21b, v21b, av).

img(i22).
v(v22a).
v(v22b).
a(a22).
v(v22c).
v(v22d).
v(v22e).
ligne(l22).
circle(c22a).
blank(b22).
circle(c22b).
sep(i22, l22).
up(l22, [v22a, v22b, a22, v22c, v22d, v22e]).
down(l22, [c22a, b22, c22b]).
cor(c22a, v22a, v22b).
cor(b22, a22, v22c).
cor(c22b, v22d, v22e).
res(v22a, v22b, vv).
res(a22, v22c, av).
res(v22d, v22e, vv).

img(i31).
v(v31).
a(a31a).
a(a31b).
a(a31c).
a(a31d).
ligne(l31).
rectangle(r31).
triangle(t31).
sep(i31, l31).
up(l31, [v31, a31a, a31b, a31c, a31d]).
down(l31, [r31, t31]).
cor(r31, v31, a31a).
cor(t31, a31b, a31c).
res(v31, a31a, va).
res(a31b, a31c, aa).

img(i32).
v(v32a).
a(a32).
v(v32b).
ligne(l32).
rectangle(r32).
sep(i32, l32).
up(l32, [v32a, a32, v32b]).
down(l32, [r32]).
cor(r32, v32a, a32).
res(v32a, a32, va).

% neg

img(i13).
a(a13a).
v(v13).
a(a13b).
ligne(l13).
rectangle(r13).
sep(i13, l13).
up(l13, [a13a, v13, a13b]).
down(l13, [r13]).
cor(r13, a13a, v13).
res(a13a, v13, av).

img(i14).
v(v14a).
v(v14b).
v(v14c).
v(v14d).
ligne(l14).
triangle(t14a).
triangle(t14b).
sep(i14, l14).
up(l14, [v14a, v14b, v14c, v14d]).
down(l14, [t14a, t14b]).
cor(t14a, v14a, v14b).
cor(t14b, v14c, v14d).
res(v14a, v14b, vv).
res(v14c, v14d, vv).

img(i23).
v(v23a).
v(v23b).
v(v23c).
a(a23a).
a(a23b).
a(a23c).
ligne(l23).
triangle(t23).
blank(b23).
circle(c23).
sep(i23, l23).
up(l23, [v23a, v23b, v23c, a23a, a23b, a23c]).
down(l23, [t23, b23, c23]).
cor(t23, v23a, v23b).
cor(b23, v23c, a23a).
cor(c23, a23b, a23c).
res(v23a, v23b, vv).
res(v23c, a23a, va).
res(a23b, a23c, aa).

img(i24).
v(v24a).
a(a24a).
v(v24b).
a(a24b).
a(a24c).
ligne(l24).
blank(b24a).
blank(b24b).
sep(i24, l24).
up(l24, [v24a, a24a, v24b, a24b, a24c]).
down(l24, [b24a, b24b]).
cor(b24a, v24a, a24a).
cor(b24b, v24b, a24b).
res(v24a, a24a, va).
res(v24b, a24b, va).

img(i33).
a(a33a).
a(a33b).
a(a33c).
v(v33).
ligne(l33).
circle(c33).
rectangle(r33).
sep(i33, l33).
up(l33, [a33a, a33b, a33c, v33]).
down(l33, [c33, r33]).
cor(c33, a33a, a33b).
cor(r33, a33c, v33).
res(a33a, a33b, aa).
res(a33c, v33, av).

img(i34).
v(v34a).
v(v34b).
v(v34c).
v(v34d).
ligne(l34).
triangle(t34).
sep(i34, l34).
up(l34, [v34a, v34b, v34c, v34d]).
down(l34, [t34]).
cor(t34, v34b, v34c).
res(v34a, v34b, vv).
res(v34c, v34d, vv).

% pos non vu

img(i90).
v(v90a).
v(v90b).
v(v90c).
v(v90d).
ligne(l90).
circle(c90a).
circle(c90b).
sep(i90, l90).
up(l90, [v90a, v90b, v90c, v90d]).
down(l90, [c90a, c90b]).
cor(c90a, v90a, v90b).
cor(c90b, v90c, v90d).
res(v90a, v90b, vv).
res(v90c, v90d, vv).

img(i91).
v(v91a).
a(a91a).
v(v91b).
a(a91b).
ligne(l91).
rectangle(r91a).
rectangle(r91b).
sep(i91, l91).
up(l91, [v91a, a91a, v91b, a91b]).
down(l91, [r91a, r91b]).
cor(r91a, v91a, a91a).
cor(r91b, v91b, a91b).
res(v91a, a91a, va).
res(v91b, a91b, va).

img(i92).
a(a92a).
a(a92b).
a(a92c).
a(a92d).
ligne(l92).
triangle(t92a).
triangle(t92b).
sep(i92, l92).
up(l92, [a92a, a92b, a92c, a92d]).
down(l92, [t92a, t92b]).
cor(t92a, a92a, a92b).
cor(t92b, a92c, a92d).
res(a92a, a92b, aa).
res(a92c, a92d, aa).

img(i93).
v(v93a).
v(v93b).
a(a93a).
a(a93b).
v(v93c).
a(a93c).
ligne(l93).
circle(c93).
triangle(t93).
rectangle(r93).
sep(i93, l93).
up(l93, [v93a, v93b, a93a, a93b, v93c, a93c]).
down(l93, [c93, t93, r93]).
cor(c93, v93a, v93b).
cor(t93, a93a, a93b).
cor(r93, v93c, a93c).
res(v93a, v93b, vv).
res(a93a, a93b, aa).
res(v93c, a93c, va).

img(i94).
a(a94).
v(v94).
ligne(l94).
blank(b94).
sep(i94, l94).
up(l94, [a94, v94]).
down(l94, [b94]).
cor(b94, a94, v94).
res(a94, v94, av).

% neg non vu

img(i95).
v(v95a).
v(v95b).
a(a95).
v(v95c).
ligne(l95).
triangle(t95).
rectangle(r95).
sep(i95, l95).
up(l95, [v95a, v95b, a95, v95c]).
down(l95, [t95, r95]).
cor(t95, v95a, v95b).
cor(r95, a95, v95c).
res(v95a, v95b, vv).
res(a95, v95v, av).

img(i96).
a(a96a).
a(a96b).
v(v96a).
v(v96b).
ligne(l96).
circle(c96).
triangle(t96).
sep(i96, l96).
up(l96, [a96a, a96b, v96a, v96b]).
down(l96, [c96, t96]).
cor(c96, a96a, a96b).
cor(t96, v96a, v96b).
res(a96a, a96b, aa).
res(v96a, v96b, vv).

img(i97).
v(v97a).
a(a97).
v(v97b).
ligne(l97).
blank(b97).
sep(i97, l97).
up(l97, [v97a, a97, v97b]).
down(l97, [b97]).
cor(b97, v97a, a97).
res(v97a, a97, va).

img(i98).
v(v98a).
a(a98).
v(v98b).
v(v98c).
ligne(l98).
blank(b98).
triangle(t98).
sep(i98, l98).
up(l98, [v98a, a98, v98b, v98c]).
down(l98, [b98, t98]).
cor(b98, v98a, a98).
cor(t98, v98b, v98c).
res(v98a, a98, va).
res(v98b, v98c, vv).

img(i99).
v(v99a).
v(v99b).
a(a99a).
v(v99c).
a(a99b).
a(a99c).
ligne(l99).
triangle(t99).
rectangle(r99).
circle(c99).
sep(i99, l99).
up(l99, [v99a, v99b, a99a, v99c, a99b, a99c]).
down(l99, [t99, r99, c99]).
cor(t99, v99a, v99b).
cor(b99, a99a, v99c).
cor(c99, a99b, a99c).
res(v99a, v99b, vv).
res(v99c, a99a, av).
res(a99b, a99c, aa).

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
