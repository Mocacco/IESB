import React from "react";
import { View, TextInput, Text, TouchableOpacity } from "react-native";
import { labels } from "./labels";
import { styles } from "../Styles/styles";

const UserForm = ({ name, phone, onNameChange, onPhoneChange, onRegister }) => {
  return (
    <View>
      <Text style={styles.title}>{labels.title}</Text>

      <View style={styles.inputContainer}>
        <Text style={styles.label}>{labels.name}</Text>
        <TextInput
          style={styles.input}
          value={name}
          onChangeText={onNameChange}
        />
      </View>

      <View style={styles.inputContainer}>
        <Text style={styles.label}>{labels.phone}</Text>
        <TextInput
          style={styles.input}
          value={phone}
          onChangeText={onPhoneChange}
          keyboardType="phone-pad"
        />
      </View>

      <TouchableOpacity style={styles.button} onPress={onRegister}>
        <Text style={styles.buttonText}>{labels.register}</Text>
      </TouchableOpacity>

      <View style={styles.line} />
    </View>
  );
};

export default UserForm;