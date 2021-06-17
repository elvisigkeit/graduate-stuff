package prototype.arctos.cash_e.controller

import android.content.Context
import android.support.v7.widget.RecyclerView
import android.text.Layout
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.LinearLayout
import android.widget.TextView
import prototype.arctos.cash_e.R
import prototype.arctos.cash_e.model.Expense

class ExpenseListAdapter internal constructor(
    context: Context
) : RecyclerView.Adapter<ExpenseListAdapter.ExpenseViewHolder>() {

    private val inflater: LayoutInflater = LayoutInflater.from(context)
    private var expenses = emptyList<Expense>() // Cached copy of words

    inner class ExpenseViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {
        val expenseViewHolder: LinearLayout = itemView.findViewById(R.id.recyclerview_item)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ExpenseViewHolder {
        val itemView = inflater.inflate(R.layout.recyclerview_item, parent, false)
        return ExpenseViewHolder(itemView)
    }

    override fun onBindViewHolder(holder: ExpenseViewHolder, position: Int) {
        val current = expenses[position]
        val date = holder.expenseViewHolder.findViewById<TextView>(R.id.recyclerview_date)
        val value = holder.expenseViewHolder.findViewById<TextView>(R.id.recyclerview_value)
        date.text = current.time.toString()
        value.text = current.cost.toString()
    }

    internal fun setExpenses(expenses: List<Expense>) {
        this.expenses = expenses
        notifyDataSetChanged()
    }

    override fun getItemCount() = expenses.size
}