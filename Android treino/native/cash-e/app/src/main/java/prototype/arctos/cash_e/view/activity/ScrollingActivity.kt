package prototype.arctos.cash_e.view.activity

import android.app.Activity
import android.arch.lifecycle.Observer
import android.arch.lifecycle.ViewModelProviders
import android.content.Intent
import android.os.Bundle
import android.support.design.widget.Snackbar
import android.support.v7.app.AppCompatActivity
import android.support.v7.widget.LinearLayoutManager
import android.support.v7.widget.RecyclerView
import android.view.LayoutInflater
import android.view.Menu
import android.view.MenuItem
import android.widget.Toast
import kotlinx.android.synthetic.main.activity_scrolling.*
import prototype.arctos.cash_e.R
import prototype.arctos.cash_e.controller.ExpenseListAdapter
import prototype.arctos.cash_e.controller.ExpenseViewModel

class ScrollingActivity : AppCompatActivity() {

    private val newExpenseActivityRequestCode = 1
    private lateinit var expenseViewModel: ExpenseViewModel

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_scrolling)

        val viewRecicler = LayoutInflater.from(this).inflate(R.layout.recyclerview_main, null)
        val recyclerViewExpenses = viewRecicler.findViewById<RecyclerView>(R.id.recyclerview_expenses)
        val adapter = ExpenseListAdapter(this)
        recyclerViewExpenses.adapter = adapter
        recyclerViewExpenses.layoutManager = LinearLayoutManager(this)

        expenseViewModel = ViewModelProviders.of(this).get(ExpenseViewModel::class.java)
        expenseViewModel.allExpenses.observe(this, Observer { expenses ->
            // Update the cached copy of the words in the adapter.
            expenses?.let { adapter.setExpenses(it) }
        })

        fab.setOnClickListener { _ ->
            val intent = Intent(this@ScrollingActivity, NewExpenseActivity::class.java)
            startActivityForResult(intent, newExpenseActivityRequestCode)
        }
    }

    override fun onCreateOptionsMenu(menu: Menu): Boolean {
        // Inflate the menu; this adds items to the action bar if it is present.
        menuInflater.inflate(R.menu.menu_scrolling, menu)
        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.

        return when (item.itemId) {
            R.id.action_settings -> true
            else -> super.onOptionsItemSelected(item)
        }
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, intentData: Intent?) {
        super.onActivityResult(requestCode, resultCode, intentData)

        if (requestCode == newExpenseActivityRequestCode && resultCode == Activity.RESULT_OK) {
            intentData?.let { _ ->
                //val expense = Expense(data.getStringExtra(NewWordActivity.EXTRA_REPLY))
                //expenseViewModel.insert(expense)
            }
        } else {
            Toast.makeText(
                applicationContext,
                R.string.empty_not_saved,
                Toast.LENGTH_LONG
            ).show()
        }
    }
}
