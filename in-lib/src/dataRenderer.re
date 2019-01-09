let component = ReasonReact.statelessComponent("DataRenderer");

let make = (~state: ThunkedStore.appState, ~dispatch, _children) => {
  let incrementIfOdd =
      (
        store:
          Reductive.Store.t(
            ReduxThunk.thunk(ThunkedStore.appState),
            ThunkedStore.appState,
          ),
      ) =>
    switch (Reductive.Store.getState(store)) {
    | {counter} when counter mod 2 === 1 =>
      Reductive.Store.dispatch(
        store,
        ThunkedStore.CounterAction(SimpleStore.Increment),
      )
    | _ => ()
    };
  let incrementAsync = store =>
    ignore(
      Js.Global.setTimeout(
        () =>
          Reductive.Store.dispatch(
            store,
            ThunkedStore.CounterAction(SimpleStore.Increment),
          ),
        1000,
      ),
    );
  {
    ...component,
    render: _self =>
      <div>
        <div> {ReasonReact.string("string: " ++ state.notACounter)} </div>
        <div>
          {ReasonReact.string("counter: " ++ string_of_int(state.counter))}
        </div>
        <button
          onClick={_ =>
            dispatch(ThunkedStore.CounterAction(SimpleStore.Increment))
          }>
          {ReasonReact.string("Increment")}
        </button>
        <button
          onClick={_ =>
            dispatch(ThunkedStore.CounterAction(SimpleStore.Decrement))
          }>
          {ReasonReact.string("Decrement")}
        </button>
        <button
          onClick={_ => dispatch(ThunkedStore.StringAction(ThunkedStore.A))}>
          {ReasonReact.string("add a")}
        </button>
        <button onClick={_ => dispatch(ReduxThunk.Thunk(incrementAsync))}>
          {ReasonReact.string("Increment Async")}
        </button>
        <button onClick={_ => dispatch(ReduxThunk.Thunk(incrementIfOdd))}>
          {ReasonReact.string("Increment if Odd")}
        </button>
      </div>,
  };
};
