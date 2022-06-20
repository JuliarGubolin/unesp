import React, {useState}  from 'react';
import { Text, View, StyleSheet, TextInput, Button, SafeAreaView, TouchableOpacity, Image } from 'react-native';

export default function App() {

  const [descricao, setDescricao] = useState('');
  const [images,setImages] =  useState("./images/cachorro.png");

  function apareceDescricao(){
    setDescricao("Cachorro brabo demaiis!!!!!!!!");
    setImages("./images/cachorro_bravo.png")
    return descricao;
  }

  return (
    <SafeAreaView style={{flex: 1, backgroundColor:"#fff"}}>
      <View style={styles.container}>
        <TouchableOpacity
          activeOpacity={0.5}
          onPress = {apareceDescricao}>
          <Image source={require(images)} style={{width:100, height:100}} />
        </TouchableOpacity>
        <Text style={{color:"#000"}}>{descricao}</Text>
      </View>
      
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    margin: 10,
    marginTop: 200,
    padding: 30,
  },
  buttonImageIconStyle: {
    padding: 10,
    margin: 5,
    height: 25,
    width: 25,
    resizeMode: 'stretch',
  },
});