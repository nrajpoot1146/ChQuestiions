from flask import Flask, render_template, request
app = Flask(__name__, template_folder="")

# root route to access home page
@app.route('/')
def root():
   return render_template('index.html') # render homepage to user

# route to handle form submit request
@app.route('/form', methods=['POST'])
def form_submit():
    val = request.form.get('q1') # access form value
    return "<h1>"+ val +" was your answer</h1>" # return responce to user

if __name__ == '__main__':
   app.run()