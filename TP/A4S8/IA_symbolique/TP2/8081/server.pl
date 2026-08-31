#!/usr/bin/env swipl

:- use_module(library(main)).
:- use_module(library(settings)).

:- use_module(library(http/http_server)).
:- use_module(library(http/http_unix_daemon)).
:- use_module(library(http/http_json)).
:- use_module(library(http/http_error)).
:- use_module(library(http/http_log)).
:- use_module(library(http/http_cors)).

:- set_setting(http:logfile, 'httpd.log').
:- set_setting(http:cors, [*]).

:- cors_enable.

:- debug.

:- use_module(update).

:- initialization(run, main).

run :- 
    http_log_stream(_),
    debug(http(_)),
    ( current_prolog_flag(windows, true) ->
        http_server(http_dispatch, [port(8081)])
        ;
        http_daemon([fork(false), interactive(false), port(8081)])
    ).

:- http_handler(root(action), handle_action_request, []).

belief(Belief, Belief, forward).

handle_action_request(Request) :-
   option(method(options), Request), !,
   cors_enable(Request, [methods([put])]),
   format('Content-type: text/plain\r\n'),
   format('~n').

handle_action_request(Request) :-
    http_read_json_dict(Request, RequestJSON, [value_string_as(atom)]),
    _{
        beliefs: HunterBeliefs, 
        percepts: Percepts
    } :< RequestJSON,
    http_log_stream(Stream),
    print_term(_{
        beliefs: HunterBeliefs,
        percepts: Percepts 
    }, [output(Stream),nl(true)]),

    calculer_action_croyances(HunterBeliefs, Percepts, NewBeliefs, Action),

    % belief(HunterBeliefs, NewBeliefs, Action),
    
    cors_enable,
    reply_json_dict(_{
        hunterState: _{
            beliefs:NewBeliefs, percepts: Percepts
        }, 
        action: Action
    }).