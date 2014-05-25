package com.example.projet_ihm;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.GregorianCalendar;
import java.util.Locale;

import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.GridView;
import android.widget.RelativeLayout;
import android.widget.TextView;

public class MainActivity extends Activity {
	
	public GregorianCalendar month, itemmonth;// calendar instances.
	public CalendarAdapter adapter;// adapter instance
	public Handler handler;// for grabbing some event values for showing the dot marker.
	public ArrayList<String> items; //list declaration
	
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		Locale.setDefault( Locale.FRANCE );
		
		month = (GregorianCalendar) GregorianCalendar.getInstance();
		itemmonth = (GregorianCalendar) month.clone();
		items = new ArrayList<String>();
		adapter = new CalendarAdapter(this,month);
		
		GridView gridview = (GridView)findViewById(R.id.gridView1);
		gridview.setAdapter(adapter); //set gridview adapter
		
		handler = new Handler();
		handler.post(calendarUpdater);
		
		refreshCalendar();
		
		//click listener for previous button
		RelativeLayout previous = (RelativeLayout) this.findViewById(R.id.relativeLayout1);
        previous.setOnClickListener(new OnClickListener() {

            public void onClick(View v) {
                setPreviousMonth();
                refreshCalendar();
            }
        });

        //click listener for next button
        RelativeLayout next = (RelativeLayout) this.findViewById(R.id.relativeLayout2);
        next.setOnClickListener(new OnClickListener() {

            public void onClick(View v) {
                setNextMonth();
                refreshCalendar();

            }
        });
		
        //click listener on gridview item
		gridview.setOnItemClickListener(new OnItemClickListener() {
			public void onItemClick(AdapterView<?> parent, View v,
					int position, long id) {

				((CalendarAdapter) parent.getAdapter()).setSelected(v);
				String selectedGridDate = CalendarAdapter.dayString
						.get(position);
				String[] separatedTime = selectedGridDate.split("-");
				String gridvalueString = separatedTime[0].replaceFirst("^0*",
						"");// taking first part of date. ie; 2 from 02-12-2012.
				int gridvalue = Integer.parseInt(gridvalueString);
				// navigate to next or previous month on clicking offdays.
                if ((gridvalue > 10) && (position < 8)) {
                    setPreviousMonth();
                    refreshCalendar();
                } else if ((gridvalue < 7) && (position > 28)) {
                    setNextMonth();
                    refreshCalendar();
                }
				((CalendarAdapter) parent.getAdapter()).setSelected(v);


			}
		});
	}

	protected void setNextMonth() {
		//if december
		if (month.get(GregorianCalendar.MONTH) == month.getActualMaximum(GregorianCalendar.MONTH)) {
			//go to january of the next year
            month.set((month.get(GregorianCalendar.YEAR) + 1),month.getActualMinimum(GregorianCalendar.MONTH), 1);
        } else {
            month.set(GregorianCalendar.MONTH,month.get(GregorianCalendar.MONTH) + 1);
        }

	}

	protected void setPreviousMonth() {
		//if january
		if (month.get(GregorianCalendar.MONTH) == month.getActualMinimum(GregorianCalendar.MONTH)) {
			//go to december of the previous year
            month.set((month.get(GregorianCalendar.YEAR) - 1),month.getActualMaximum(GregorianCalendar.MONTH), 1);
        } else {
            month.set(GregorianCalendar.MONTH,month.get(GregorianCalendar.MONTH) - 1);
        }

	}



	public void refreshCalendar() {
		//Update the month in the textView
		TextView title = (TextView) this.findViewById(R.id.textView);
		title.setText(android.text.format.DateFormat.format("MMMM yyyy", month));
		
		adapter.refreshDays();
		adapter.notifyDataSetChanged();
		handler.post(calendarUpdater); // generate some calendar items	
	}

	public Runnable calendarUpdater = new Runnable() {

		@Override
		public void run() {
			items.clear();

			// Print dates of the current week
			SimpleDateFormat df = new SimpleDateFormat("dd-MM-yyyy",Locale.FRANCE);
			String itemvalue;
			for (int i = 0; i < 5; i++) {
				itemvalue = df.format(itemmonth.getTime());
				itemmonth.add(GregorianCalendar.DATE, 1);
				items.add("2014-01-15");
				items.add("2014-03-28");
				items.add("2014-07-13");
				items.add("2014-07-20");
			}

			adapter.setItems(items);
			adapter.notifyDataSetChanged();
		}
	};

}
