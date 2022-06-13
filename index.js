
const { create } = require('./build/Release/program.node')

class Program{
  constructor() {}

  create(data) {
    const string = JSON.stringify(data)
    return new Promise((resolve) => {
      create(string, (err, result) => {
        resolve(result)
      })
    })
  }

}
module.exports = Program;
