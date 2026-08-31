
% a enlever
interface_pair_ell(Ls, NLs) :-
	dissocie_pair_ell(Ls, [], NLs).

associer_pair_ell(K, _, [], NLs, K-NLs).
associer_pair_ell(K, V, [X-Y|Ls], Acc, NLs) :-
	write(X),nl,
	Mul #= Y*V,
	associer_pair_ell(K, V, Ls, [X-Mul|Acc], NLs).

dissocie_pair([], _, NLs, NLs).
dissocie_pair(E, Ell, _, E-Ell).
dissocie_pair([K-V|Ls], Ell, Acc, NLs) :- 
	write(Ell),nl,
	associer_pair_ell(K, V, Ell, [], NNLs),
	write(NNLs),nl,
	dissocie_pair(Ls, Ell, [NNLs|Acc], NLs).

dissocie_pair_ell([], NLs, NLs).
dissocie_pair_ell([K-V|Ls], Acc, NLs) :-
	write(K),nl,
	flatten(V, Ell),
	write(Ell),nl,
	dissocie_pair(K, Ell, [], NNLs),
	write(aa),nl,
	dissocie_pair_ell(Ls, [NNLs|Acc], NLs).
% enlever precedement
