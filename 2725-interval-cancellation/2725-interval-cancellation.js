/**************************😎**************************/
const cancellable=(e,l,t)=>{let a=0;return e(...l),a=setInterval((()=>e(...l)),t),()=>{clearInterval(a)}};