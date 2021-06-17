package prototype.arctos.cash_e.controller

import android.arch.lifecycle.LiveData
import android.arch.persistence.room.Dao
import android.arch.persistence.room.Insert
import android.arch.persistence.room.Query
import prototype.arctos.cash_e.model.Expense

@Dao
interface ExpenseDAO {

    @Query("SELECT * from expense ORDER BY time DESC")
    fun getAllExpenses(): LiveData<List<Expense>>

    @Insert
    fun insert(expense: Expense)

    @Query("DELETE FROM expense")
    fun deleteAll()
}