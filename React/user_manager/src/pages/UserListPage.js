import React, { useState, useEffect } from "react";
import ListItem from "../Components/ListItem";

const UserListPage = () => {
  let [users, setUsers] = useState([]);

  useEffect(() => {
    getUsers();
  }, []);

  let getUsers = () => {
    let response = require("../api/users.json");
    console.log(response);
    setUsers(response);
  };

  return (
    <div className="users-list">
      <table className="users-table" cellpadding="2" cellspacing="2">
        <thead>
          <tr>
            <th>Name</th>
            <th>Email</th>
            <th>Mobile</th>
            <th></th>
            <th></th>
          </tr>
        </thead>
        <tbody>
          {users.map((user, index) => (
            <ListItem key={index} user={user} />
          ))}
        </tbody>
      </table>
    </div>
  );
};

export default UserListPage;
