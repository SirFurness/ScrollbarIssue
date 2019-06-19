open Revery;
open Revery.UI;
open Revery.UI.Components;

let specialButton = {
  let component = React.component("SpecialButton");

  (~children as _ : list(React.syntheticElement), ()) =>
    component(hooks => {
      let (children, setChildren, hooks) = Hooks.state([] : list(React.syntheticElement), hooks);
      let containerStyle = Style.[border(~width=2, ~color=Colors.white)];

      let addChild = () => {
        let newChild =
          <View style=containerStyle>
            <Button width=200 height=200 title="special button" />
            <View style=containerStyle>...children</View>
          </View>;
        setChildren([newChild, ...children]);
      };
      
      (
        hooks, 
        <View style=containerStyle>
          <View style=containerStyle>...children</View>
          <Button width=200 height=200 title="special button" onClick=addChild/>
        </View>);
    });
};

let init = app => {
  let win = App.createWindow(app, "Scrollbar Issue");

  let scrollStyle = Style.[width(128), height(128), backgroundColor(Colors.black)];
  
  let element =
    <ScrollView style=scrollStyle>
      <specialButton />
    </ScrollView>;

  let _ = UI.start(win, element);
};

App.start(init);
