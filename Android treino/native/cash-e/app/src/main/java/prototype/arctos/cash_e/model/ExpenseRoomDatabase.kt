package prototype.arctos.cash_e.model

import android.arch.persistence.db.SupportSQLiteDatabase
import android.arch.persistence.room.Database
import android.arch.persistence.room.Room
import android.arch.persistence.room.RoomDatabase
import android.arch.persistence.room.TypeConverters
import android.content.Context
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch
import prototype.arctos.cash_e.controller.ExpenseDAO
import prototype.arctos.cash_e.utils.DateTypeConverter
import java.sql.Date
import java.time.LocalDateTime
import java.time.ZoneOffset

@Database(entities = [Expense::class], version = 1, exportSchema = false)
@TypeConverters(DateTypeConverter::class)
abstract class ExpenseRoomDatabase : RoomDatabase() {

    abstract fun expenseDao(): ExpenseDAO

    companion object {
        @Volatile
        private var INSTANCE: ExpenseRoomDatabase? = null

        fun getDatabase(context: Context, scope: CoroutineScope): ExpenseRoomDatabase {
            val tempInstance = INSTANCE
            if (tempInstance != null) {
                return tempInstance
            }
            synchronized(this) {
                val instance = Room.databaseBuilder(
                    context.applicationContext,
                    ExpenseRoomDatabase::class.java,
                    "ExpenseDatabase"
                )
                    .fallbackToDestructiveMigration()
                    .addCallback(ExpenseDatabaseCallback(scope))
                    .build()
                INSTANCE = instance
                return instance
            }
        }

        private class ExpenseDatabaseCallback(
            private val scope: CoroutineScope
        ) : RoomDatabase.Callback() {

            override fun onOpen(db: SupportSQLiteDatabase) {
                super.onOpen(db)
                INSTANCE?.let { database ->
                    scope.launch(Dispatchers.IO) {
                        populateDatabase(database.expenseDao())
                    }
                }
            }
        }

        private fun populateDatabase(expenseDAO: ExpenseDAO) {
            expenseDAO.deleteAll()

            var expenseEx1 = Expense(time = Date.from(LocalDateTime.now().toInstant(ZoneOffset.MIN)) as? Date, cost = 100.0)
            var expenseEx2 = Expense(time = Date.from(LocalDateTime.now().toInstant(ZoneOffset.MIN)) as? Date, cost = 650.0)
            expenseDAO.insert(expenseEx1)
            expenseDAO.insert(expenseEx2)
        }
    }
}