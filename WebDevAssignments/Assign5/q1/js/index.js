

generateTable(userData)
function generateTable(userData){
    if(userData.length === 0){
        document.getElementById('data').innerHTML='<h3>Loading....</h3>'
        return;
    }

    document.getElementById("data").innerHTML= `
    <table>
    <tbody>
    
<thead>
    <tr>
        <th> Name</th>
        <th> Age</th>
    </tr>
</thead>
       ${
        userData.map(user=>{
          return `  <tr>
            <td> ${user.name} </td>
            <td> ${user.age}  </td>
     
        </tr>`
        }).join("")
       }
    </tbody>
</table>
    `
    
}