% Empty with aleph loaded
:- use_module(library(aleph)).
:- aleph.

:- modeh(*, left(+img)).

:- modeb(*, contains(+img,-fig)).
:- modeb(*, in(+fig, -fig)).
:- modeb(*, taille(+fig, +fig)).


:- determination(left/1,contains/2).
:- determination(left/1,in/2).
:- determination(left/1, taille/2).

% left(I) :- contains(I, F1), in(F1, F2), taille(F1, F2).

:- aleph_set(i,10).

:- aleph_set(verbosity,10).

:-begin_bg.

fig(F) :- figure(F).

taille(F1, F2) :- cote(F1, T1), cote(F2, T2), T1 > T2.

% pos

img(i11).
figure(q11).
figure(t11).
contains(i11, q11).
in(q11, t11).
cote(q11, 4).
cote(t11, 3).

img(i12).
figure(h12).
figure(q12).
contains(i12, h12).
in(h12, q12).
cote(h12, 6).
cote(q12, 4).

img(i21).
figure(p21).
figure(t21).
contains(i21, p21).
in(p21, t21).
cote(p21, 5).
cote(t21, 3).

img(i22).
figure(h22).
figure(p22).
contains(i22, h22).
in(h22, p22).
cote(h22, 6).
cote(p22, 5).

img(i31).
figure(h31).
figure(t31).
contains(i31, h31).
in(h31, t31).
cote(h31, 6).
cote(t31, 3).

img(i32).
figure(p32).
figure(q32).
contains(i32, p32).
in(p32, q32).
cote(p32, 5).
cote(q32, 4).

% neg 

img(i13).
figure(t13).
figure(h13).
contains(i13, t13).
in(t13, h13).
cote(t13, 3).
cote(h13, 6).

img(i14).
figure(q14).
figure(p14).
contains(i14, q14).
in(q14, p14).
cote(q14, 4).
cote(p14, 5).

img(i23).
figure(q23).
figure(h23).
contains(i23, q23).
in(q23, h23).
cote(q23, 4).
cote(h23, 6).

img(i24).
figure(t24).
figure(q24).
contains(i24, t24).
in(t24, q24).
cote(t24, 3).
cote(q24, 4).

img(i33).
figure(t33).
figure(p33).
contains(i33, t33).
in(t33, p33).
cote(t33, 3).
cote(p33, 5).

img(i34).
figure(p34).
figure(h34).
contains(i34, p34).
in(p34, h34).
cote(p34, 5).
cote(h34, 6).


% pos non vu

img(i90).
figure(o90).
figure(t90).
contains(i90, o90).
in(o90, t90).
cote(o90, 8).
cote(t90, 3).

img(i91).
figure(o91).
figure(q91).
contains(i91, o91).
in(o91, q91).
cote(o91, 8).
cote(q91, 4).

img(i92).
figure(o92).
figure(h92).
contains(i92, o92).
in(o92, h92).
cote(o92, 8).
cote(h92, 6).

img(i93).
figure(h93).
figure(q93).
contains(i93, h93).
in(h93, q93).
cote(h93, 7).
cote(q93, 4).

img(i94).
figure(n94).
figure(o94).
contains(i94, n94).
in(n94, o94).
cote(n94, 9).
cote(o94, 8).

% neg non vu

img(i95).
figure(o95).
figure(n95).
contains(i95, o95).
in(o95, n95).
cote(o95, 8).
cote(n95, 9).

img(i96).
figure(t96).
figure(o96).
contains(i96, t96).
in(t96, o96).
cote(t96, 3).
cote(o96, 8).

img(i97).
figure(q97).
figure(o97).
contains(i97, q97).
in(q97, o97).
cote(q97, 4).
cote(o97, 8).

img(i98).
figure(q98).
figure(h98).
contains(i98, h98).
in(q98, h98).
cote(q98, 4).
cote(h98, 7).

img(i99).
figure(p99).
figure(h99).
contains(i99, p99).
in(q99, p99).
cote(p99, 5).
cote(h99, 7).


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
