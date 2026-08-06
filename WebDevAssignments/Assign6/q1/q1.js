//calculator


function* calculator(initialValue){
let result= initialValue;
while(true){
    const {op,value}= yield result;

    if (typeof value !== "number") {
      throw new Error("Invalid input");
     }
    switch(op){
        case "add":
            result+=value;
            break;
        case "multiply":
            result*=value;
            break;
        case "subtract":
            result-=value;
            break;
        case "divide":
            if(value!==0){
                result/=value;

            }else{
                throw new Error("Cannot divide by zero");
            }
            break;
        default:
            throw new Error("Invalid operation");
    }
}
}

const calc= calculator(50);
// calc.next();//50
// calc.next({op: "add", value: 30}) // 80
// calc.next({op: "multiply", value: 2}) // 160
// calc.next({op: "add", value: 30}) // 190
// calc.next({op: "multiply", value: 0}) // 0