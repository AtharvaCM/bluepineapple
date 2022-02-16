/* eslint-disable react-hooks/exhaustive-deps */
import React, { useState, useEffect } from "react";
import { useParams } from "react-router-dom";

const UserPage = () => {
  let params = useParams();
  console.log("params", params);
  let userId = params.id;

  let [user, setUser] = useState({});

  useEffect(() => {
    getUser();
  }, []);

  let getUser = () => {
    let response = require("../api/users.json");
    let data = response.find((user) => user.id === userId);
    console.log("get user data", data);
    setUser(data);
  };

  return (
    <div className="user">
      <h3>Name: {user.name}</h3>
      <p>Email: {user.email}</p>
      <p>Mobile: {user.mobile}</p>
    </div>
  );
};

export default UserPage;
